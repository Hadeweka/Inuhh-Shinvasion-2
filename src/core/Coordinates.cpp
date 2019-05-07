#include "Coordinates.h"

mrb_value ruby_coordinates_init(mrb_state* mrb, mrb_value self) {

	float x = 0.0;
	float y = 0.0;

	mrb_get_args(mrb, "|ff", &x, &y);

	MrbWrap::convert_to_instance_variable<sf::Vector2f>(mrb, self, "@_vector", "vector", x, y);

	return self;

}

mrb_value ruby_coordinates_x(mrb_state* mrb, mrb_value self) {

	auto content = MrbWrap::convert_from_instance_variable<sf::Vector2f>(mrb, self, "@_vector");
	
	return mrb_float_value(mrb, content->x);

}

mrb_value ruby_coordinates_y(mrb_state* mrb, mrb_value self) {

	auto content = MrbWrap::convert_from_instance_variable<sf::Vector2f>(mrb, self, "@_vector");

	return mrb_float_value(mrb, content->y);

}

mrb_value ruby_coordinates_x_equals(mrb_state* mrb, mrb_value self) {

	return mrb_nil_value();

}

mrb_value ruby_coordinates_y_equals(mrb_state* mrb, mrb_value self) {

	return mrb_nil_value();

}

mrb_value ruby_coordinates_get(mrb_state* mrb, mrb_value self) {

	return mrb_nil_value();

}

mrb_value ruby_coordinates_set(mrb_state* mrb, mrb_value self) {

	return mrb_nil_value();

}

void setup_ruby_class_coordinates(mrb_state* mrb) {

	auto ruby_coordinates_class = mrb_define_class(mrb, "Coordinates", mrb->object_class);

	mrb_define_method(mrb, ruby_coordinates_class, "initialize", ruby_coordinates_init, MRB_ARGS_OPT(2));
	mrb_define_method(mrb, ruby_coordinates_class, "x", ruby_coordinates_x, MRB_ARGS_NONE());
	mrb_define_method(mrb, ruby_coordinates_class, "y", ruby_coordinates_y, MRB_ARGS_NONE());

}