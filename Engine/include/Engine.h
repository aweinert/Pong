#pragma once

#include <iostream>
#include <set>

#include "../deps/SDL/SDL.h"

class Entity {};

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

class DrawableEntity {
public:
    virtual void draw(Canvas& canvas) = 0;

};

class Engine {
public:
	Engine();
	void register_entity(std::shared_ptr<Entity> entity);
	void remove_entity(std::shared_ptr<Entity> entity);

    void register_drawable_entity(std::shared_ptr<DrawableEntity> entity);
    void remove_drawable_entity(std::shared_ptr<DrawableEntity> entity);

	void run_main_loop();

private:
	std::set<std::shared_ptr<Entity>> living_entities;
	std::set<std::shared_ptr<DrawableEntity>> drawable_entities;

    Canvas* canvas;
};
