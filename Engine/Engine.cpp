#include "Engine.h"

#include <SDL.h>

using namespace std;

Canvas::Canvas(int width, int height) :
	window(std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>(SDL_CreateWindow("SDL Window", 100, 100, width, height, SDL_WINDOW_SHOWN), SDL_DestroyWindow))
{
	this->width = width;
	this->height = height;
	this->renderer = std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(this->window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC), SDL_DestroyRenderer);
}

void Canvas::clear()
{
	SDL_SetRenderDrawColor(this->renderer.get(), 0x00, 0x00, 0x00, 0xFF);

	if (SDL_RenderClear(this->renderer.get()) != 0) {
		std::cout << "SDL_RenderClear error" << SDL_GetError() << std::endl;
	}
}

void Canvas::draw_line(int xStart, int yStart, int xEnd, int yEnd, int r, int g, int b, int alpha)
{
	SDL_Renderer* renderer = this->renderer.get();
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, r, g, b, alpha);
	SDL_RenderDrawLine(renderer, xStart, yStart, xEnd, yEnd);
}

void Canvas::blip()
{
	SDL_RenderPresent(this->renderer.get());
}

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

void Engine::register_drawable_entity(std::shared_ptr<DrawableEntity> entity)
{
	this->drawable_entities.insert(entity);
}

void Engine::remove_drawable_entity(std::shared_ptr<DrawableEntity> entity)
{
	auto entity_to_remove = this->drawable_entities.find(entity);
	this->drawable_entities.erase(entity_to_remove);
}

void Engine::run_main_loop()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init error" << SDL_GetError() << std::endl;
	}

	this->canvas = new Canvas(640, 480);

	bool quit_requested = false;

	while (!quit_requested) {
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit_requested = true;
			}
		}

		this->canvas->clear();

		for (auto drawableEntityIterator = begin(this->drawable_entities);
				drawableEntityIterator != end(this->drawable_entities);
				++drawableEntityIterator) {
			(*drawableEntityIterator)->draw(*(this->canvas));
		}

		this->canvas->blip();

		SDL_Delay(0);
	}
}
