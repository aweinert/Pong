#pragma once

#include <iostream>
#include <set>

class Entity {};

class Engine {
public:
	Engine();
	void register_entity(std::shared_ptr<Entity> entity);
	void remove_entity(std::shared_ptr<Entity> entity);

private:
	std::set<std::shared_ptr<Entity>> living_entities;
};
