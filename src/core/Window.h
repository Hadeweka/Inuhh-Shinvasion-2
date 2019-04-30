#include "../scripting/Helper.h"

#include <SFML/Graphics.hpp>

mrb_value ruby_window_init(mrb_state* mrb, mrb_value self);
mrb_value ruby_window_clear(mrb_state* mrb, mrb_value self);
mrb_value ruby_window_display(mrb_state* mrb, mrb_value self);