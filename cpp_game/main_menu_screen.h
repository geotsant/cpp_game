#pragma once
#include "screen.h"
#include "button.h"
#include <vector>

class MainMenuScreen : public Screen {
public:
    void draw() override;
    void update(float deltaTime) override;
    void handleInput() override;
    void init();

    static MainMenuScreen* getInstance();
    MainMenuScreen();
private:

    static MainMenuScreen* m_instance;
    std::vector<Button> m_buttons;
};