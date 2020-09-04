#include <Engine.h>

class Rectangle : public DrawableEntity {
public:
	Rectangle(int width, int height) : width(width), height(height), xPos(0), yPos(0) {}

	void move(int xPos, int yPos) {
		this->xPos = xPos;
		this->yPos = yPos;
	}

	virtual void draw(Canvas& canvas) {
		canvas.draw_line(xPos, yPos, xPos + width, yPos, 255, 255, 255, 255);
		canvas.draw_line(xPos, yPos + height, xPos + width, yPos + height, 255, 255, 255, 255);
		canvas.draw_line(xPos, yPos, xPos, yPos + height, 255, 255, 255, 255);
		canvas.draw_line(xPos + width, yPos, xPos + width, yPos + height, 255, 255, 255, 255);
	}

private:
	int xPos, yPos, width, height;
};

int main(int argc, char** argv) {
	Engine engine;

	std::shared_ptr<Rectangle> rectangle = std::shared_ptr<Rectangle>(new Rectangle(100, 200));
	rectangle->move(100, 100);

	engine.register_drawable_entity(rectangle);

	engine.run_main_loop();

	return 0;
}