#include "RubyWrapper.h"

RubyWrapper::RubyWrapper() {

	mrb = mrb_open();

}

void RubyWrapper::exec(std::string const& expression) {

	auto c_string_expression = expression.c_str();
	mrb_load_string(mrb, c_string_expression);

}