//! Essentially, this code just wraps the SFML sprite class into a superclass for the later Entity class in Ruby

#pragma once

#include "Helper.h"

#include <SFML/Graphics.hpp>

mrb_value ruby_core_entity_init(mrb_state* mrb, mrb_value self);
mrb_value ruby_core_entity_link_texture(mrb_state* mrb, mrb_value self);

mrb_value ruby_core_entity_position(mrb_state* mrb, mrb_value self);
mrb_value ruby_core_entity_position_equals(mrb_state* mrb, mrb_value self);

mrb_value ruby_core_entity_draw(mrb_state* mrb, mrb_value self);

void setup_ruby_class_core_entity(mrb_state* mrb);