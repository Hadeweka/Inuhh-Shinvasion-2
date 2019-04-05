#pragma once

#include <mruby.h>
#include <mruby/compile.h>

#include <string>

class RubyWrapper {

public:

	RubyWrapper();
	void RubyWrapper::exec(std::string const& expression);

private:

	mrb_state* mrb;

};