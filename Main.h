#pragma once

#include <SFML/Graphics.hpp>

#include <filesystem>
#include <iostream>

#include "Helper.h"

#ifdef NDEBUG
#include "compiled_scripts/Scene.h"
#include "compiled_scripts/Scenes.h"
#include "compiled_scripts/GlobalContainer.h"
#include "compiled_scripts/Entity.h"
#include "compiled_scripts/Entities.h"
#include "compiled_scripts/MainLoop.h"
#include "compiled_scripts/Main.h"
#endif

#include "ResourceManager.h"
#include "Coordinates.h"
#include "CoreEntity.h"
#include "Window.h"
#include "Texture.h"
#include "Map.h"