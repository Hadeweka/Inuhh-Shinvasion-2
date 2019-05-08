#include "CoreEntity.h"

#include <iostream>

mrb_value ruby_core_entity_init(mrb_state* mrb, mrb_value self) {

	MrbWrap::convert_to_instance_variable<sf::Sprite>(mrb, self, "@_sprite", "sprite");

	return self;

}

mrb_value ruby_core_entity_set_texture(mrb_state* mrb, mrb_value self) {

	mrb_value ruby_texture;

	mrb_get_args(mrb, "o", &ruby_texture);

	auto sprite = MrbWrap::convert_from_instance_variable<sf::Sprite>(mrb, self, "@_sprite");
	auto texture = MrbWrap::convert_from_instance_variable<sf::Texture>(mrb, ruby_texture, "@_texture");

	sprite->setTexture(*texture);

	return mrb_true_value();

}

mrb_value ruby_core_entity_position(mrb_state* mrb, mrb_value self) {

	auto sprite = MrbWrap::convert_from_instance_variable<sf::Sprite>(mrb, self, "@_sprite");

	static auto coordinates_class = mrb_class_get(mrb, "Coordinates");

	auto new_coordinates = mrb_obj_new(mrb, coordinates_class, 0, NULL);
	auto new_vector = MrbWrap::convert_from_instance_variable<sf::Vector2f>(mrb, new_coordinates, "@_vector");

	*new_vector = sprite->getPosition();

	return new_coordinates;

}

mrb_value ruby_core_entity_position_equals(mrb_state* mrb, mrb_value self) {

	mrb_value ruby_coordinates;

	mrb_get_args(mrb, "o", &ruby_coordinates);

	auto sprite = MrbWrap::convert_from_instance_variable<sf::Sprite>(mrb, self, "@_sprite");
	auto coordinates = MrbWrap::convert_from_instance_variable<sf::Vector2f>(mrb, ruby_coordinates, "@_vector");

	sprite->setPosition(*coordinates);

	return ruby_coordinates;

}

void setup_ruby_class_core_entity(mrb_state* mrb) {

	auto ruby_core_entity_class = mrb_define_class(mrb, "CoreEntity", mrb->object_class);

	mrb_define_method(mrb, ruby_core_entity_class, "initialize", ruby_core_entity_init, MRB_ARGS_NONE());
	
	mrb_define_method(mrb, ruby_core_entity_class, "set_texture", ruby_core_entity_set_texture, MRB_ARGS_REQ(1));

	mrb_define_method(mrb, ruby_core_entity_class, "position", ruby_core_entity_position, MRB_ARGS_NONE());
	mrb_define_method(mrb, ruby_core_entity_class, "position=", ruby_core_entity_position_equals, MRB_ARGS_REQ(1));

}