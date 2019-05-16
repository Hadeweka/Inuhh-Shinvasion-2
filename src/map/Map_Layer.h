#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.h"

class Map_Layer : public sf::Drawable, public sf::Transformable {

public:

	void initialize_mesh(unsigned int view_width, unsigned int view_height);
	void generate_mesh(float cam_x, float cam_y);
	void load_tiles(unsigned int width, unsigned int height, std::shared_ptr<unsigned int> frame_counter_ptr);

	void set_tile(unsigned int x, unsigned int y, unsigned int tile_id);

private:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	unsigned int width;
	unsigned int height;

	unsigned int view_width;
	unsigned int view_height;

	unsigned int background_tile;

	std::vector<std::vector<unsigned int>> tiles;
	sf::VertexArray vertices;

	sf::Texture tileset;
	std::vector<Tile> tile_data;

	std::shared_ptr<unsigned int> frame_counter_ptr;

};