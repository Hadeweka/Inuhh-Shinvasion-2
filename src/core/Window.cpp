#include "Window.h"

mrb_value ruby_window_init(mrb_state* mrb, mrb_value self) {

	char* title;
	int width;
	int height;
	bool fullscreen = false;

	mrb_get_args(mrb, "zii|b", &title, &width, &height, &fullscreen);

	if (fullscreen) {

		MrbWrap::convert_to_instance_variable<sf::RenderWindow>(mrb, self, "@_window", "window", 
			sf::VideoMode(width, height), title, sf::Style::Fullscreen);

	} else {

		MrbWrap::convert_to_instance_variable<sf::RenderWindow>(mrb, self, "@_window", "window", 
			sf::VideoMode(width, height), title);

	}

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

mrb_value ruby_window_enable_vertical_sync(mrb_state* mrb, mrb_value self) {

	auto window = MrbWrap::convert_from_instance_variable<sf::RenderWindow>(mrb, self, "@_window");
	window->setVerticalSyncEnabled(true);

	return mrb_true_value();

}

mrb_value ruby_window_is_open(mrb_state* mrb, mrb_value self) {

	auto window = MrbWrap::convert_from_instance_variable<sf::RenderWindow>(mrb, self, "@_window");

	return mrb_bool_value(window->isOpen());

}

mrb_value ruby_window_close(mrb_state* mrb, mrb_value self) {

	auto window = MrbWrap::convert_from_instance_variable<sf::RenderWindow>(mrb, self, "@_window");
	window->close();

	return mrb_nil_value();

}

void setup_ruby_class_window(mrb_state* mrb) {

	auto ruby_window_class = mrb_define_class(mrb, "Window", mrb->object_class);

	mrb_define_method(mrb, ruby_window_class, "initialize", ruby_window_init, MRB_ARGS_ARG(3, 1));

	mrb_define_method(mrb, ruby_window_class, "clear", ruby_window_clear, MRB_ARGS_NONE());
	mrb_define_method(mrb, ruby_window_class, "display", ruby_window_display, MRB_ARGS_NONE());

	mrb_define_method(mrb, ruby_window_class, "enable_vertical_sync", ruby_window_enable_vertical_sync, MRB_ARGS_NONE());

	mrb_define_method(mrb, ruby_window_class, "is_open?", ruby_window_is_open, MRB_ARGS_NONE());

	mrb_define_method(mrb, ruby_window_class, "close", ruby_window_close, MRB_ARGS_NONE());

}