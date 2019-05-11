#include "ResourceManager.h"

ResourceManager::ResourceManager() {

}

ResourceManager::~ResourceManager() {

}

unsigned int ResourceManager::add_sprite() {

	sprites.push_back(std::make_shared<sf::Sprite>());

	return sprites.size() - 1;

}

void ResourceManager::delete_sprite(unsigned int index) {

	sprites.erase(sprites.begin() + index);

}

std::shared_ptr<sf::Sprite> ResourceManager::access_sprite(unsigned int index) {

	return sprites[index];

}

mrb_value ruby_resource_manager_init(mrb_state* mrb, mrb_value self) {

	MrbWrap::convert_to_instance_variable<ResourceManager>(mrb, self, "@_manager", "manager");

	return self;

}

mrb_value test_manager(mrb_state* mrb, mrb_value self) {

	auto ptr = MrbWrap::convert_from_instance_variable<ResourceManager>(mrb, self, "@_manager");

	ptr->add_sprite();

	return mrb_nil_value();

}

mrb_value test_manager_2(mrb_state* mrb, mrb_value self) {

	auto ptr = MrbWrap::convert_from_instance_variable<ResourceManager>(mrb, self, "@_manager");

	ptr->delete_sprite(0);

	return mrb_nil_value();

}

void setup_ruby_class_resource_manager(mrb_state* mrb) {

	auto ruby_resource_manager_class = mrb_define_class(mrb, "ResourceManager", mrb->object_class);

	mrb_define_method(mrb, ruby_resource_manager_class, "initialize", ruby_resource_manager_init, MRB_ARGS_NONE());
	mrb_define_method(mrb, ruby_resource_manager_class, "test", test_manager, MRB_ARGS_NONE());
	mrb_define_method(mrb, ruby_resource_manager_class, "test2", test_manager_2, MRB_ARGS_NONE());

	//! TODO: Replace test methods with proper methods
	//! TODO: Link sprite directly to CoreEntity class (shared_ptr as instance variable)
	//! TODO: Deletion methods for sprites which removes it from the manager

}