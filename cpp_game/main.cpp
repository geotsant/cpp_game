#include "sgg/graphics.h"
#include "define.h"
#include <string>
#include "game.h"

void draw() {
	Game* mygame = Game::getInstance();
	mygame->draw();
}

void update(float deltaTime) {
	Game* mygame = Game::getInstance();
	mygame->update(deltaTime);
}

void handleInput() {
	Game* mygame = Game::getInstance();
	mygame->handleInput();
}

int main(int argc, char** argv) {
	graphics::createWindow(512, 512, "Raccoon-Chase");

	Game* game = Game::getInstance();
	game->init();

	graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
	setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);

	graphics::startMessageLoop(); //***************************************

	Game::releaseInstance();

	return 0;
}