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
	sf::Sprite* access_sprite(int index);

private:

	//! Use unique_ptr to optimize performance, and just give out raw pointers
	std::vector<std::unique_ptr<sf::Sprite>> contents;
	std::queue<int> free_spots;

};

mrb_value ruby_resource_manager_init(mrb_state* mrb, mrb_value self);

void setup_ruby_class_resource_manager(mrb_state* mrb);