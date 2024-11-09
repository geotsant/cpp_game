#include "help_screen.h"
#include "sgg/graphics.h"
#include "define.h"
#include "button.h"
#include "game.h"
#include "main_menu_screen.h"

constexpr float CANVAS_CENTER_X = CANVAS_WIDTH / 2;
constexpr float CANVAS_CENTER_Y = CANVAS_HEIGHT / 2;

HelpScreen* HelpScreen::m_instance = nullptr;


HelpScreen::HelpScreen() {
    m_buttons.push_back(Button(1.5f, 1.5f, 2.0f, 2.0f, "<-", []() {  //-------------------------------------------------------------------edw------------------------------------------------
        Game::getInstance()->getScreenManager()->pushScreen(new MainMenuScreen());
    }));
}

HelpScreen* HelpScreen::getInstance() {
    if (!m_instance) {
        m_instance = new HelpScreen();
    }
    return m_instance;
}

void HelpScreen::draw() {
    graphics::Brush br;
    br.outline_opacity = 0.0f;
    br.texture = ASSET_PATH + std::string("raccoon-chase.png");
    drawRect(CANVAS_CENTER_X, CANVAS_CENTER_Y, CANVAS_WIDTH, CANVAS_HEIGHT, br);

    for (auto& button : m_buttons) {
        button.draw();
    }
}

void HelpScreen::update(float deltaTime) {
    for (auto& button : m_buttons) {
        button.update();
    }
}

void HelpScreen::handleInput() {
    for (auto& button : m_buttons) {
        button.handleInput();
    }
}
