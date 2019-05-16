#pragma once

#include "Helper.h"

#include <SFML/Graphics.hpp>

mrb_value ruby_texture_init(mrb_state* mrb, mrb_value self);
mrb_value ruby_texture_load_from_file(mrb_state* mrb, mrb_value self);

void setup_ruby_class_texture(mrb_state* mrb);