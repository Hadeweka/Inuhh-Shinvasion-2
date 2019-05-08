#include "Coordinates.h"

mrb_value ruby_coordinates_init(mrb_state* mrb, mrb_value self) {

	float x = 0.0;
	float y = 0.0;

	//! Default arguments yield a zero vector
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

	float new_value;

	mrb_get_args(mrb, "f", &new_value);

	auto content = MrbWrap::convert_from_instance_variable<sf::Vector2f>(mrb, self, "@_vector");
	content->x = new_value;

	return mrb_float_value(mrb, new_value);

}

mrb_value ruby_coordinates_y_equals(mrb_state* mrb, mrb_value self) {

	float new_value;

	mrb_get_args(mrb, "f", &new_value);

	auto content = MrbWrap::convert_from_instance_variable<sf::Vector2f>(mrb, self, "@_vector");
	content->y = new_value;

	return mrb_float_value(mrb, new_value);

}

mrb_value ruby_coordinates_plus(mrb_state* mrb, mrb_value self) {

	mrb_value other_value;

	mrb_get_args(mrb, "o", &other_value);

	auto this_vector = MrbWrap::convert_from_instance_variable<sf::Vector2f>(mrb, self, "@_vector");
	auto other_vector = MrbWrap::convert_from_instance_variable<sf::Vector2f>(mrb, other_value, "@_vector");

	//! No need to call this over and over again
	static auto coordinates_class = mrb_class_get(mrb, "Coordinates");

	auto new_value = mrb_obj_new(mrb, coordinates_class, 0, NULL);
	auto new_vector = MrbWrap::convert_from_instance_variable<sf::Vector2f>(mrb, new_value, "@_vector");

	//! The SFML vector has overloaded operators, so we can just do this the easy way
	//! Technically, the whole methods just creates an empty Coordinates object and then directly modifies its contents
	*new_vector = *this_vector + *other_vector;

	return new_value;

}

mrb_value ruby_coordinates_minus(mrb_state* mrb, mrb_value self) {

	mrb_value other_value;

	mrb_get_args(mrb, "o", &other_value);

	auto this_vector = MrbWrap::convert_from_instance_variable<sf::Vector2f>(mrb, self, "@_vector");
	auto other_vector = MrbWrap::convert_from_instance_variable<sf::Vector2f>(mrb, other_value, "@_vector");

	static auto coordinates_class = mrb_class_get(mrb, "Coordinates");

	auto new_value = mrb_obj_new(mrb, coordinates_class, 0, NULL);
	auto new_vector = MrbWrap::convert_from_instance_variable<sf::Vector2f>(mrb, new_value, "@_vector");

	*new_vector = *this_vector - *other_vector;

	return new_value;

}

mrb_value ruby_coordinates_times(mrb_state* mrb, mrb_value self) {

	float scalar;

	mrb_get_args(mrb, "f", &scalar);

	auto this_vector = MrbWrap::convert_from_instance_variable<sf::Vector2f>(mrb, self, "@_vector");

	static auto coordinates_class = mrb_class_get(mrb, "Coordinates");

	auto new_value = mrb_obj_new(mrb, coordinates_class, 0, NULL);
	auto new_vector = MrbWrap::convert_from_instance_variable<sf::Vector2f>(mrb, new_value, "@_vector");

	*new_vector = *this_vector * scalar;

	return new_value;

}

mrb_value ruby_coordinates_dot_product(mrb_state* mrb, mrb_value self) {

	mrb_value other_value;

	mrb_get_args(mrb, "o", &other_value);

	auto this_vector = MrbWrap::convert_from_instance_variable<sf::Vector2f>(mrb, self, "@_vector");
	auto other_vector = MrbWrap::convert_from_instance_variable<sf::Vector2f>(mrb, other_value, "@_vector");

	return mrb_float_value(mrb, this_vector->x * other_vector->x + this_vector->y * other_vector->y);

}

mrb_value ruby_coordinates_squared_norm(mrb_state* mrb, mrb_value self) {

	auto content = MrbWrap::convert_from_instance_variable<sf::Vector2f>(mrb, self, "@_vector");

	return mrb_float_value(mrb, content->x * content->x + content->y * content->y);
}

mrb_value ruby_coordinates_to_s(mrb_state* mrb, mrb_value self) {

	auto content = MrbWrap::convert_from_instance_variable<sf::Vector2f>(mrb, self, "@_vector");

	char buffer[100];
	snprintf(buffer, 100, "%.8g %.8g", content->x, content->y);

	return mrb_str_new_cstr(mrb, buffer);

}

mrb_value ruby_coordinates_inspect(mrb_state* mrb, mrb_value self) {

	auto content = MrbWrap::convert_from_instance_variable<sf::Vector2f>(mrb, self, "@_vector");

	char buffer[100];
	snprintf(buffer, 100, "(%.8g | %.8g)", content->x, content->y);

	return mrb_str_new_cstr(mrb, buffer);

}

void setup_ruby_class_coordinates(mrb_state* mrb) {

	auto ruby_coordinates_class = mrb_define_class(mrb, "Coordinates", mrb->object_class);

	mrb_define_method(mrb, ruby_coordinates_class, "initialize", ruby_coordinates_init, MRB_ARGS_OPT(2));

	mrb_define_method(mrb, ruby_coordinates_class, "x", ruby_coordinates_x, MRB_ARGS_NONE());
	mrb_define_method(mrb, ruby_coordinates_class, "y", ruby_coordinates_y, MRB_ARGS_NONE());

	mrb_define_method(mrb, ruby_coordinates_class, "x=", ruby_coordinates_x_equals, MRB_ARGS_NONE());
	mrb_define_method(mrb, ruby_coordinates_class, "y=", ruby_coordinates_y_equals, MRB_ARGS_NONE());

	mrb_define_method(mrb, ruby_coordinates_class, "+", ruby_coordinates_plus, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, ruby_coordinates_class, "-", ruby_coordinates_minus, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, ruby_coordinates_class, "*", ruby_coordinates_times, MRB_ARGS_REQ(1));

	mrb_define_method(mrb, ruby_coordinates_class, "dot", ruby_coordinates_dot_product, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, ruby_coordinates_class, "squared_norm", ruby_coordinates_squared_norm, MRB_ARGS_NONE());

	mrb_define_method(mrb, ruby_coordinates_class, "to_s", ruby_coordinates_to_s, MRB_ARGS_NONE());
	mrb_define_method(mrb, ruby_coordinates_class, "inspect", ruby_coordinates_inspect, MRB_ARGS_NONE());

}