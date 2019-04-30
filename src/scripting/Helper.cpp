#include "Helper.h"

void MrbWrap::execute_string(mrb_state* mrb, std::string const& code) {

	mrb_load_string(mrb, code.c_str());

}

void MrbWrap::execute_bytecode_file(mrb_state* mrb, std::string const& filename) {

	FILE* f;
	auto error_code = fopen_s(&f, filename.c_str(), "r");
	
	if (error_code != 0) {

		//! TODO: Error handling

	}

	mrb_load_irep_file(mrb, f);

	if(f) fclose(f);

}

void MrbWrap::execute_bytecode(mrb_state* mrb, const uint8_t* symbol_array) {

	mrb_load_irep(mrb, symbol_array);

}

void MrbWrap::execute_script_file(mrb_state* mrb, std::string const& filename) {

	FILE* f;
	auto error_code = fopen_s(&f, filename.c_str(), "r");

	if (error_code != 0) {

		//! TODO: Error handling

	}

	mrb_load_file(mrb, f);

	if(f) fclose(f);

}