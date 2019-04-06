#include "Main.h"

void test(mrb_state* mrb) {

	execute_ruby_bytecode_file(mrb, "scripts/test.mrb");

}

int main() {

	auto mrb = mrb_open();

	mrb_load_string(mrb, "class Test;def initialize(arg); puts arg; end; end");
	mrb_load_string(mrb, "Test.new('This is a test')");

	test(mrb);
	mrb_load_string(mrb, "puts 'Test value ' + Shape.new(30, 10).a.to_s");

	auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Inuhh Shinvasion 2");
	window->setVerticalSyncEnabled(true);

	while (window->isOpen()) {
		window->clear();
		window->display();
	}

	mrb_close(mrb);

	return 0;

}
