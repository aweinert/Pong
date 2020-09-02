#include "Engine.h"

using namespace std;

Engine::Engine()
{
}

void Engine::register_entity(std::shared_ptr<Entity> entity)
{
	this->living_entities.insert(entity);
}

void Engine::remove_entity(std::shared_ptr<Entity> entity)
{
	auto entity_to_remove = this->living_entities.find(entity);
	this->living_entities.erase(entity_to_remove);
}
