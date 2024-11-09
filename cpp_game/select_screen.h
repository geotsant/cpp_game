#pragma once
#include "screen.h"
#include <vector>
#include "button.h"

class SelectScreen : public Screen {
public:
    char e;      //indicating easy mode
    char m;      //indicating medium mode
    char h;      //indicating hard mode

    void draw() override;
    void update(float deltaTime) override;
    void handleInput() override;
    void init();

    static SelectScreen* getInstance();
    SelectScreen();

private:
    static SelectScreen* m_instance;
    std::vector<Button> m_buttons;
};