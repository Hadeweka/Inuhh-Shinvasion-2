#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Helper.h"

#ifdef NDEBUG
#include "compiled_scripts/Scene.h"
#include "compiled_scripts/GlobalContainer.h"
#include "compiled_scripts/Entity.h"
#endif

#include "CoreEntity.h"
#include "Window.h"