#include "CoreEntity.h"

#include <iostream>

mrb_value ruby_core_entity_init(mrb_state* mrb, mrb_value self) {

	MrbWrap::convert_to_instance_variable<sf::Sprite>(mrb, self, "@_sprite", "sprite");

	std::cout << "Initializing works!" << std::endl;

	return self;

}

void setup_ruby_class_core_entity(mrb_state* mrb) {

	auto ruby_core_entity_class = mrb_define_class(mrb, "CoreEntity", mrb->object_class);

	mrb_define_method(mrb, ruby_core_entity_class, "initialize", ruby_core_entity_init, MRB_ARGS_NONE());

}