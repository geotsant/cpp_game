#pragma once

class Screen {
public:
    enum screen_t {MENU_SCREEN, LOADING_SCREEN, HELP_SCREEN, SELECT_SCREEN, GAME_SCREEN};

    void init();

    virtual void draw() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void handleInput() = 0;
    virtual ~Screen() {}
};




