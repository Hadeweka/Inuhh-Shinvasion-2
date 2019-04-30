#include "Window.h"

mrb_value ruby_window_init(mrb_state* mrb, mrb_value self) {

	MrbWrap::convert_to_instance_variable<sf::RenderWindow>(mrb, self, "@_window", "window", sf::VideoMode(800, 600), "Inuhh Shinvasion 2");

	return self;

}

mrb_value ruby_window_clear(mrb_state* mrb, mrb_value self) {

	auto window = MrbWrap::convert_from_instance_variable<sf::RenderWindow>(mrb, self, "@_window");
	window->clear();

	return mrb_nil_value();

}

mrb_value ruby_window_display(mrb_state* mrb, mrb_value self) {

	auto window = MrbWrap::convert_from_instance_variable<sf::RenderWindow>(mrb, self, "@_window");
	window->display();

	return mrb_nil_value();

}