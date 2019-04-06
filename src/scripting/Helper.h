#include <mruby.h>
#include <mruby/dump.h>
#include <string>

void execute_ruby_bytecode_file(mrb_state* mrb, std::string const& filename);