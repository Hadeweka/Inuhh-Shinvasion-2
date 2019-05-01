#include "Main.h"

int main() {

	auto mrb = mrb_open();

	MRB_LOAD_SCRIPT(mrb, GlobalContainer);
	MRB_LOAD_SCRIPT(mrb, Entity);

	setup_ruby_class_window(mrb);

	MRB_LOAD_SCRIPT(mrb, Scene);

	MrbWrap::execute_string(mrb, "$window = Window.new('Inuhh Shinvasion 2', 800, 600);$window.enable_vertical_sync;$scene = Scene.new");

	MrbWrap::execute_string(mrb, "while $window.is_open? do\n$scene.main_draw\nend\n$window.close");

	mrb_close(mrb);

	return 0;

}
