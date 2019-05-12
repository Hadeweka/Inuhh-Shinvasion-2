#include "ResourceManager.h"

ResourceManager::ResourceManager() {

}

ResourceManager::~ResourceManager() {

}

int ResourceManager::add_sprite() {

	if (free_spots.empty()) {

		contents.push_back(std::make_shared<sf::Sprite>());
		return contents.size() - 1;

	} else {

		auto index = free_spots.front();
		contents[index] = std::make_shared<sf::Sprite>();
		free_spots.pop();

		return index;

	}
}

void ResourceManager::delete_sprite(int index) {

	contents[index] = nullptr;
	free_spots.push(index);

}

std::shared_ptr<sf::Sprite> ResourceManager::access_sprite(int index) {

	return contents[index];

}

mrb_value ruby_resource_manager_init(mrb_state* mrb, mrb_value self) {

	MrbWrap::convert_to_instance_variable<ResourceManager>(mrb, self, "@_manager", "manager");

	return self;

}

void setup_ruby_class_resource_manager(mrb_state* mrb) {

	auto ruby_resource_manager_class = mrb_define_class(mrb, "ResourceManager", mrb->object_class);

	mrb_define_method(mrb, ruby_resource_manager_class, "initialize", ruby_resource_manager_init, MRB_ARGS_NONE());

}