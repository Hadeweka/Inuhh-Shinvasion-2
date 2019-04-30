#pragma once

#include <mruby.h>
#include <mruby/dump.h>
#include <mruby/variable.h>
#include <mruby/data.h>
#include <mruby/compile.h>
#include <string>

namespace MrbWrap {

	//! Some different ways to execute mruby code

	void execute_string(mrb_state* mrb, std::string const& code);	//! Execute a string containing mruby code
	void execute_script_file(mrb_state* mrb, std::string const& filename);	//! Ececute a mruby script file
	[[deprecated("May not work in many situations")]] void execute_bytecode_file(mrb_state* mrb, std::string const& filename);	//! Execute a file containing mruby bytecode
	void execute_bytecode(mrb_state* mrb, const uint8_t* symbol_array);	//! Execute embedded bytecode from a C array

	template <class T> static void free_data(mrb_state* mrb, void* object_ptr) {

		reinterpret_cast<T*>(object_ptr)->~T();

	}

	template <class T, class ... TArgs> void convert_to_instance_variable(mrb_state* mrb, mrb_value self, const char* var_c_str, const char* data_type_c_str, TArgs ... args) {

		auto new_object = new T(args...);

		static const struct mrb_data_type data_type = {

			data_type_c_str, free_data<T>

		};

		auto symbol = mrb_intern_static(mrb, var_c_str, strlen(var_c_str));	//! mrb_intern_lit does not work here, because string lengths are pretty weird in mruby
		auto wrapper = Data_Wrap_Struct(mrb, mrb->object_class, &data_type, new_object);

		mrb_iv_set(mrb, self, symbol, mrb_obj_value(wrapper));

	}

	template <class T> T* convert_from_instance_variable(mrb_state* mrb, mrb_value self, const char* var_c_str) {

		auto symbol = mrb_intern_static(mrb, var_c_str, strlen(var_c_str));
		auto type = DATA_TYPE(mrb_iv_get(mrb, self, symbol));

		return reinterpret_cast<T*>(mrb_data_get_ptr(mrb, mrb_iv_get(mrb, self, symbol), type));

	}

}

//! Idea: Construct array of symbols somewhere to speed up process
//! Ideally something like std::map in the shape of: mrb_sym* get_mrb_symbol(mrb_state* mrb, const char* name)
//! If the symbol map entry is not intialized, the function will initialize it immediately
//! Should technically work!