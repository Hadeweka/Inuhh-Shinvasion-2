#include "Main.h"

using namespace std;

static mrb_value mrb_greet(mrb_state* mrb, mrb_value self) {
	printf("Hello, mruby!\n");
	return mrb_nil_value();
}

int main()
{
	mrb_state *mrb = mrb_open();

	mrb_define_method(mrb, mrb->object_class, "greet!", mrb_greet, MRB_ARGS_NONE());

	char code[] = "greet!";

	mrb_load_string(mrb, code);

	auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Inuhh Shinvasion 2");
	window->setVerticalSyncEnabled(true);

	while (window->isOpen()) {
		window->clear();
		window->display();
	}

	return 0;
}
