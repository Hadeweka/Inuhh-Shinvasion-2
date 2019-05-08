#pragma once

#include <mruby.h>
#include <mruby/dump.h>
#include <mruby/variable.h>
#include <mruby/data.h>
#include <mruby/compile.h>
#include <string>

//! Preprocessor shenanigans to switch between script file loading and pre-compiled bytecode
//! If debug mode is on (NDEBUG not defined), the macro will directly load the script file "scripts/XXX.rb"
//! If debug mode is off, the macro will execute the bytecode in the respective array compiled_ruby_XXX
//! In the latter case, don't forget to include "compiled_scripts/XXX.h" (but ONLY then), or else the array will not be defined
//! Sadly, there is no easy way to circumwent the conditioned include directive
#ifndef NDEBUG
#define MRB_LOAD_SCRIPT(mrb, name) MrbWrap::execute_script_file(mrb, "scripts/" #name ".rb")
#else
#define MRB_LOAD_SCRIPT(mrb, name) MrbWrap::execute_bytecode(mrb, compiled_ruby_##name)
#endif

namespace MrbWrap {

	//! Some different ways to execute mruby code

	//! Execute a string containing mruby code
	//! Only useful for user-generated input
	//! If C++ code needs to execute ruby commands, don't use this
	void execute_string(mrb_state* mrb, std::string const& code);

	//! Ececute a mruby script file
	//! Easiest way to execute script files, but also the slowest
	void execute_script_file(mrb_state* mrb, std::string const& filename);

	//! Execute a file containing mruby bytecode
	//! WARNING: Does not work correctly for some reason, so this should NEVER be used!
	[[deprecated("May not work in many situations")]] void execute_bytecode_file(mrb_state* mrb, std::string const& filename);

	//! Execute embedded bytecode from a C array
	//! Fastest way to load a script, but needs some setup work
	void execute_bytecode(mrb_state* mrb, const uint8_t* symbol_array);

	template <class T> static void free_data(mrb_state* mrb, void* object_ptr) {

		reinterpret_cast<T*>(object_ptr)->~T();

	}

	//! Creates a C++ instance of the class 'T' and wraps it directly into the ruby instance variable of the ruby object 'self'
	//! Constructor arguments can be given as 'TArgs', if needed
	//! DO NOT destroy the created object manually, the mruby garbage collector will do this for you!
	template <class T, class ... TArgs> T* convert_to_instance_variable(mrb_state* mrb, mrb_value self, const char* var_c_str, const char* data_type_c_str, TArgs ... args) {

		auto new_object = new T(args...);

		static const struct mrb_data_type data_type = {

			data_type_c_str, free_data<T>

		};

		//! mrb_intern_lit does not work here, because string lengths are pretty weird in mruby
		//! Also, the symbols do not need to be computed more than once, so this variable is made static (also see below)
		static auto symbol = mrb_intern_static(mrb, var_c_str, strlen(var_c_str));
		auto wrapper = Data_Wrap_Struct(mrb, mrb->object_class, &data_type, new_object);

		mrb_iv_set(mrb, self, symbol, mrb_obj_value(wrapper));

		return new_object;

	}

	//! Obtains a pointer to the C++ object of class 'T' back from the instance variable with name 'var_c_str' from the ruby object 'self'
	//! This can be used to modify the internal properties of a wrapped C++ object
	template <class T> T* convert_from_instance_variable(mrb_state* mrb, mrb_value self, const char* var_c_str) {

		static auto symbol = mrb_intern_static(mrb, var_c_str, strlen(var_c_str));
		auto type = DATA_TYPE(mrb_iv_get(mrb, self, symbol));

		return reinterpret_cast<T*>(mrb_data_get_ptr(mrb, mrb_iv_get(mrb, self, symbol), type));

	}

}
