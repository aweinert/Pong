#pragma once

#include <iostream>
#include <set>

#include "../deps/SDL/SDL.h"

class Entity {};

class DrawableEntity {
public:

};

class Canvas {
public:
    Canvas(int width, int height);

    void clear();
    void draw_line(int xStart, int yStart, int xEnd, int yEnd, int r, int g, int b, int alpha);
    void blip();

private:
    int width, height;
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
    std::shared_ptr<SDL_Renderer> renderer;
};

class Engine {
public:
	Engine();
	void register_entity(std::shared_ptr<Entity> entity);
	void remove_entity(std::shared_ptr<Entity> entity);

	void run_main_loop();

private:
	std::set<std::shared_ptr<Entity>> living_entities;
    std::unique_ptr<Canvas> canvas;
};
