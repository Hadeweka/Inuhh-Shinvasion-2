#include "Helper.h"

void MrbWrap::execute_bytecode_file(mrb_state* mrb, std::string const& filename) {

	FILE* f;

	fopen_s(&f, filename.c_str(), "r");
	mrb_load_irep_file(mrb, f);
	if(f) fclose(f);

}