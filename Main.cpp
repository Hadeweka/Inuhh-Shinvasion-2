#include "Main.h"

int main() {

	auto mrb = mrb_open();

	MRB_LOAD_SCRIPT(mrb, GlobalContainer);

	MRB_LOAD_SCRIPT(mrb, Entity);

	setup_ruby_class_window(mrb);

	MRB_LOAD_SCRIPT(mrb, Scene);

	MRB_LOAD_SCRIPT(mrb, Main);

	mrb_close(mrb);

	return 0;

}
