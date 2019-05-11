#pragma once

#include <SFML/Graphics.hpp>

#include "Helper.h"

class ResourceManager {

public:

	ResourceManager();
	~ResourceManager();

	unsigned int add_sprite();
	void delete_sprite(unsigned int index);
	std::shared_ptr<sf::Sprite> access_sprite(unsigned int index);

private:

	std::vector<std::shared_ptr<sf::Sprite>> sprites;

};

mrb_value ruby_resource_manager_init(mrb_state* mrb, mrb_value self);

void setup_ruby_class_resource_manager(mrb_state* mrb);