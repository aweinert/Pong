#include <Engine.h>

int main(int argc, char** argv) {
	std::shared_ptr<Entity> entity = std::shared_ptr<Entity>(new Entity());
	Engine engine;

	engine.register_entity(entity);
	engine.remove_entity(entity);

	engine.run_main_loop();

	return 0;
}