#pragma once

#include "Helper.h"

#include <SFML/Graphics.hpp>

mrb_value ruby_coordinates_init(mrb_state* mrb, mrb_value self);

mrb_value ruby_coordinates_x(mrb_state* mrb, mrb_value self);
mrb_value ruby_coordinates_y(mrb_state* mrb, mrb_value self);

mrb_value ruby_coordinates_x_equals(mrb_state* mrb, mrb_value self);
mrb_value ruby_coordinates_y_equals(mrb_state* mrb, mrb_value self);

mrb_value ruby_coordinates_get(mrb_state* mrb, mrb_value self);
mrb_value ruby_coordinates_set(mrb_state* mrb, mrb_value self);

void setup_ruby_class_coordinates(mrb_state* mrb);