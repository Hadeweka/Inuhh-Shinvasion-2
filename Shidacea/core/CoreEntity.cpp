#include "CoreEntity.h"


mrb_value ruby_core_entity_init(mrb_state* mrb, mrb_value self) {

	mrb_value ruby_resource_manager;

	mrb_get_args(mrb, "o", &ruby_resource_manager);

	auto resource_manager = MrbWrap::convert_from_instance_variable<ResourceManager>(mrb, ruby_resource_manager, "@_manager");
	auto sprite_index = resource_manager->add_sprite();

	static auto symbol = mrb_intern_static(mrb, "@sprite_index", strlen("@sprite_index"));	//! TODO: Cache this
	mrb_iv_set(mrb, self, symbol, mrb_fixnum_value(sprite_index));
	static auto symbol_2 = mrb_intern_static(mrb, "@resource_manager", strlen("@resource_manager"));	//! TODO: Cache this
	mrb_iv_set(mrb, self, symbol_2, ruby_resource_manager);

	return self;

}

mrb_value ruby_core_entity_delete(mrb_state* mrb, mrb_value self) {

	static auto symbol = mrb_intern_static(mrb, "@resource_manager", strlen("@resource_manager"));	//! TODO: Cache this
	auto ruby_resource_manager = mrb_iv_get(mrb, self, symbol);
	auto resource_manager = MrbWrap::convert_from_instance_variable<ResourceManager>(mrb, ruby_resource_manager, "@_manager");

	static auto symbol_2 = mrb_intern_static(mrb, "@sprite_index", strlen("@sprite_index"));	//! TODO: Cache this
	auto sprite_index =  mrb_fixnum(mrb_iv_get(mrb, self, symbol_2));

	resource_manager->delete_sprite(sprite_index);

	return mrb_true_value();

}

mrb_value ruby_core_entity_link_texture(mrb_state* mrb, mrb_value self) {

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

mrb_value ruby_core_entity_draw(mrb_state* mrb, mrb_value self) {

	mrb_value ruby_window;

	mrb_get_args(mrb, "o", &ruby_window);

	auto sprite = MrbWrap::convert_from_instance_variable<sf::Sprite>(mrb, self, "@_sprite");
	auto window = MrbWrap::convert_from_instance_variable<sf::RenderWindow>(mrb, ruby_window, "@_window");

	window->draw(*sprite);

	return mrb_true_value();

}

void setup_ruby_class_core_entity(mrb_state* mrb) {

	auto ruby_core_entity_class = mrb_define_class(mrb, "CoreEntity", mrb->object_class);

	mrb_define_method(mrb, ruby_core_entity_class, "initialize", ruby_core_entity_init, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, ruby_core_entity_class, "delete", ruby_core_entity_delete, MRB_ARGS_NONE());
	
	mrb_define_method(mrb, ruby_core_entity_class, "link_texture", ruby_core_entity_link_texture, MRB_ARGS_REQ(1));

	mrb_define_method(mrb, ruby_core_entity_class, "position", ruby_core_entity_position, MRB_ARGS_NONE());
	mrb_define_method(mrb, ruby_core_entity_class, "position=", ruby_core_entity_position_equals, MRB_ARGS_REQ(1));

	mrb_define_method(mrb, ruby_core_entity_class, "draw", ruby_core_entity_draw, MRB_ARGS_REQ(1));

}