#include "Main.h"

int main() {

	auto mrb = mrb_open();

	//! Load wrapped classes and Ruby scripts
	
	setup_ruby_class_resource_manager(mrb);

	setup_ruby_class_coordinates(mrb);

	MRB_LOAD_SCRIPT(mrb, GlobalContainer);

	setup_ruby_class_texture(mrb);
	setup_ruby_class_core_entity(mrb);

	MRB_LOAD_SCRIPT(mrb, Entity);

	setup_ruby_class_window(mrb);

	MRB_LOAD_SCRIPT(mrb, Scene);

	MRB_LOAD_SCRIPT(mrb, MainLoop);

	//! Load potential mods

	auto current_path = std::filesystem::current_path();
	auto mod_path = current_path / "scripts" / "mods";

	if (!std::filesystem::exists(mod_path)) {

		std::clog << "No mod folder found." << std::endl;

	} else {

		std::clog << "Mod folder found. Loading mod files..." << std::endl;

		for (const auto& entry : std::filesystem::directory_iterator(mod_path)) {

			std::cout << "Loading file: " << entry << std::endl;
			const std::string str = entry.path().string();
			MrbWrap::execute_script_file(mrb, str);

		}

	}

	//! Start main script with the game loop

	MRB_LOAD_SCRIPT(mrb, Main);

	mrb_close(mrb);

}
