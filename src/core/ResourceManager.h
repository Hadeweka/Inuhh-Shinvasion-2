#pragma once

#include <queue>
#include <SFML/Graphics.hpp>

#include "Helper.h"

//! May be generalized into a template class

class ResourceManager {

public:

	ResourceManager();
	~ResourceManager();

	int add_sprite();
	void delete_sprite(int index);
	std::shared_ptr<sf::Sprite> access_sprite(int index);

private:

	std::vector<std::shared_ptr<sf::Sprite>> contents;
	std::queue<int> free_spots;

};

mrb_value ruby_resource_manager_init(mrb_state* mrb, mrb_value self);

void setup_ruby_class_resource_manager(mrb_state* mrb);