#pragma once
#include <stack>
#include "screen.h"

/*
 The idea is that we make a stack that holds the different screens. At hte bottom there is always the
 MainMenuScreen , because that is where we start from and at the top there is always the active screen.
 After that we push everytime the screen that we go to (e.g. we press the help button to go to the
 HelpScreen, now in the stack in the bottom we have the MainMenuScreen and on the top we have the
 HelpScreen.). ScreenManager does the job of managing that stack, pushing, popping etc.
 */
class ScreenManager {
private:
    std::stack<Screen*> screens;
public:
    void pushScreen(Screen* screen);
    void popScreen();
    void draw();
    void update(float deltaTime);
    void handleInput();

    ~ScreenManager();
};
