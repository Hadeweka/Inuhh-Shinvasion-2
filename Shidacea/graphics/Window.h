#pragma once

#include "Helper.h"

#include <SFML/Graphics.hpp>

mrb_value ruby_window_init(mrb_state* mrb, mrb_value self);
mrb_value ruby_window_clear(mrb_state* mrb, mrb_value self);
mrb_value ruby_window_display(mrb_state* mrb, mrb_value self);
mrb_value ruby_window_enable_vertical_sync(mrb_state* mrb, mrb_value self);
mrb_value ruby_window_is_open(mrb_state* mrb, mrb_value self);
mrb_value ruby_window_close(mrb_state* mrb, mrb_value self);

void setup_ruby_class_window(mrb_state* mrb);