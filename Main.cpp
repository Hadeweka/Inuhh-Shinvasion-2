#include "Main.h"

int main() {

	auto mrb = mrb_open();
	
	setup_ruby_class_resource_manager(mrb);

	setup_ruby_class_coordinates(mrb);

	MRB_LOAD_SCRIPT(mrb, GlobalContainer);

	setup_ruby_class_texture(mrb);
	setup_ruby_class_core_entity(mrb);

	MRB_LOAD_SCRIPT(mrb, Entity);

	setup_ruby_class_window(mrb);

	MRB_LOAD_SCRIPT(mrb, Scene);

	MRB_LOAD_SCRIPT(mrb, Main);

	mrb_close(mrb);

}
