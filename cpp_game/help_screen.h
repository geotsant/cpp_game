#pragma once
#include "screen.h"
#include <vector>
#include "button.h"

class HelpScreen : public Screen {
public:
    void draw() override;
    void update(float deltaTime) override;
    void handleInput() override;
    void init();

    static HelpScreen* getInstance();
    HelpScreen();

private:
    static HelpScreen* m_instance;
    std::vector<Button> m_buttons;
};