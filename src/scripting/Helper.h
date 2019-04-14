#pragma once

#include <mruby.h>
#include <mruby/dump.h>
#include <mruby/variable.h>
#include <mruby/data.h>
#include <string>

namespace MrbWrap {

	void execute_bytecode_file(mrb_state* mrb, std::string const& filename);

	template <class T> static void free_data(mrb_state* mrb, void* object_ptr) {

		reinterpret_cast<T*>(object_ptr)->~T();

	}

	template <class T> void convert_to_instance_variable(mrb_state* mrb, mrb_value self, const char* var_c_str, const char* data_type_c_str, T* new_object) {

		static const struct mrb_data_type data_type = {

			data_type_c_str, free_data<T>

		};

		mrb_sym symbol = mrb_intern_static(mrb, var_c_str, strlen(var_c_str));	//! mrb_intern_lit does not work here, because string lengths are pretty weird in mruby

		mrb_iv_set(mrb, self, symbol, mrb_obj_value(Data_Wrap_Struct(mrb, mrb->object_class, &data_type, new_object)));

	}

}

//! Idea: Construct array of symbols somewhere to speed up process
//! Ideally something like std::map in the shape of: mrb_sym* get_mrb_symbol(mrb_state* mrb, const char* name)
//! If the symbol map entry is not intialized, the function will initialize it immediately
//! Should technically work!