#include "Map.h"

void Map::load(unsigned int width, unsigned int height) {

	this->width = width;
	this->height = height;

	frame_counter_ptr = std::make_shared<unsigned int>(0);

	for (auto& map_layer : map_layers) {

		map_layer.load_tiles(width, height, frame_counter_ptr);
		map_layer.initialize_mesh(32 + 1, 18 + 1);

	}

	map_layers[2].set_tile(3, 3, 4);

}

void Map::update() {

	(*frame_counter_ptr)++;

}

void Map::reload_layers(float actor_x, float actor_y) {

	for (auto& map_layer : map_layers) {

		map_layer.generate_mesh(actor_x, actor_y);

	}

}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	states.transform *= getTransform();
	for(auto& map_layer : map_layers) target.draw(map_layer, states);

}