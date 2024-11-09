#include "select_screen.h"
#include "sgg/graphics.h"
#include "define.h"
#include "button.h"
#include "game.h"
#include "main_menu_screen.h"
#include "game_screen.h"

constexpr float CANVAS_CENTER_X = CANVAS_WIDTH / 2;
constexpr float CANVAS_CENTER_Y = CANVAS_HEIGHT / 2;

SelectScreen* SelectScreen::m_instance = nullptr;

SelectScreen::SelectScreen() {
    //back button
    m_buttons.push_back(Button(1.5f, 1.5f, 2.0f, 2.0f, "<-", []() {
        Game::getInstance()->getScreenManager()->pushScreen(new MainMenuScreen());
    }));

    //difficulties buttons
    //easy
    m_buttons.push_back(Button(CANVAS_CENTER_X, CANVAS_CENTER_Y - 4.0f, 8.0f, 2.0f, "EASY", [this]() {
        Game::getInstance()->getScreenManager()->pushScreen(new GameScreen('e'));
    }));

    //medium
    m_buttons.push_back(Button(CANVAS_CENTER_X, CANVAS_CENTER_Y - 1.5f, 8.0f, 2.0f, "MEDIUM", [this]() {
        Game::getInstance()->getScreenManager()->pushScreen(new GameScreen('m'));
    }));

    //hard
    m_buttons.push_back(Button(CANVAS_CENTER_X, CANVAS_CENTER_Y + 1.0f, 8.0f, 2.0f, "HARD", [this]() {
        Game::getInstance()->getScreenManager()->pushScreen(new GameScreen('h'));
    }));
}

SelectScreen* SelectScreen::getInstance() {
    if (!m_instance) {
        m_instance = new SelectScreen();
    }
    return m_instance;
}

void SelectScreen::draw() {
    graphics::Brush br;
    br.outline_opacity = 0.0f;
    br.texture = ASSET_PATH + std::string("raccoon-chase.png");
    drawRect(CANVAS_CENTER_X, CANVAS_CENTER_Y, CANVAS_WIDTH, CANVAS_HEIGHT, br);

    for (auto& button : m_buttons) {
        button.draw();
    }
}

void SelectScreen::update(float deltaTime) {
    for (auto& button : m_buttons) {
        button.update();
    }
}

void SelectScreen::handleInput() {
    for (auto& button : m_buttons) {
        button.handleInput();
    }
}
