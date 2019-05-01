#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include "src/scripting/Helper.h"

#ifdef NDEBUG
#include "compiled_scripts/Scene.h"
#include "compiled_scripts/GlobalContainer.h"
#include "compiled_scripts/Entity.h"
#endif

#include "src/core/Window.h"