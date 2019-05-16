#pragma once

#include <SFML/Graphics.hpp>

#include "Map_Layer.h"

#include <array>

class Map : public sf::Drawable, public sf::Transformable {

public:

	void load(unsigned int width, unsigned int height);

	void reload_layers(float actor_x, float actor_y);

	void update();

private:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	unsigned int width;
	unsigned int height;

	//! Layers: 0 - Ground, 1 - Ground Decoration, 2 - Objects
	std::array<Map_Layer, 3> map_layers;

	std::shared_ptr<unsigned int> frame_counter_ptr;

};