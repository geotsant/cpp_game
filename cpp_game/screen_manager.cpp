#include "screen_manager.h"
#include <stack>

void ScreenManager::pushScreen(Screen *screen) {
    if (screens.empty() || screens.top() != screen) {
        screens.push(screen);
    }
}

void ScreenManager::popScreen() {
    if (!screens.empty()) {
        delete screens.top();
        screens.pop();
    }
}

void ScreenManager::draw() {
    if (!screens.empty()) {
        screens.top()->draw();
    }
}

void ScreenManager::update(float deltaTime) {
    if (!screens.empty()) {
        screens.top()->update(deltaTime);
    }
}

void ScreenManager::handleInput() {
    if (!screens.empty()) {
        screens.top()->handleInput();
    }
}

ScreenManager::~ScreenManager() {
    while (!screens.empty()) {
        delete screens.top();
        screens.pop();
    }
}
