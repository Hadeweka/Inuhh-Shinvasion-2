//! Essentially, this code just wraps the SFML sprite class into a superclass for the later Entity class in Ruby

#pragma once

#include "Helper.h"

#include <SFML/Graphics.hpp>

mrb_value ruby_core_entity_init(mrb_state* mrb, mrb_value self);

void setup_ruby_class_core_entity(mrb_state* mrb);