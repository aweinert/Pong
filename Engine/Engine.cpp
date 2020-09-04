﻿#include "Engine.h"

#include <SDL.h>

using namespace std;

Canvas::Canvas(int width, int height) :
	width(width),
	height(height),
	window(std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>(SDL_CreateWindow("SDL Window", 100, 100, width, height, SDL_WINDOW_SHOWN), SDL_DestroyWindow)),
	renderer(std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(this->window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC), SDL_DestroyRenderer))
{
}

void Canvas::clear()
{
	SDL_RenderClear(this->renderer.get());
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

Engine::Engine() :
	canvas(auto_ptr<Canvas>(new Canvas(640, 480)))
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

void Engine::run_main_loop()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init error" << SDL_GetError() << std::endl;
	}
}
