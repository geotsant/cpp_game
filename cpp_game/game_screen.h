#pragma once
#include "screen.h"
#include <vector>
#include "button.h"

class GameScreen : public Screen {
    char m_difficulty;
    static GameScreen* m_instance;
    std::vector<Button> m_buttons;
public:
    void draw() override;
    void update(float deltaTime) override;
    void handleInput() override;
    void init();

    GameScreen();
    GameScreen(char difficulty);

    static GameScreen* getInstance(char difficulty);
};
