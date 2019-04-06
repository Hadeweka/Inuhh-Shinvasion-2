#include "Helper.h"

void execute_ruby_bytecode_file(mrb_state* mrb, std::string const& filename) {

	auto f = fopen(filename.c_str(), "r");
	mrb_load_irep_file(mrb, f);
	fclose(f);

}