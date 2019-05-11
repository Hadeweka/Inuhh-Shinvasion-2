#include "Main.h"

void test() {

	auto s = new sf::Sprite;

	delete s;

}

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

	//auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Test");

	//while (true) {
	//	window->clear();
	//	window->setVerticalSyncEnabled(true);
	//	test();
	//	sf::Event event;
	//	while (window->pollEvent(event)) if (event.key.code == sf::Keyboard::Escape) exit(1);
	//	window->display();
	//}

	//return 0;

}
