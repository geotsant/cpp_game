#include "main_menu_screen.h"
#include "game.h"
#include "sgg/graphics.h"
#include "define.h"
#include "screen_manager.h"
#include "help_screen.h"
#include "select_screen.h"

constexpr float CANVAS_CENTER_X = CANVAS_WIDTH / 2;
constexpr float CANVAS_CENTER_Y = CANVAS_HEIGHT / 2;

MainMenuScreen* MainMenuScreen::m_instance = nullptr;

MainMenuScreen::MainMenuScreen() { //Creating buttons with positions, labels, and callbacks
    m_buttons.push_back(Button(CANVAS_CENTER_X, CANVAS_CENTER_Y, 8.0f, 2.0f, "PLAY", []() {  //-------------------------------------------------------------------edw------------------------------------------------
        Game::getInstance()->getScreenManager()->pushScreen(new SelectScreen());
    }));
    m_buttons.push_back(Button(CANVAS_CENTER_X, CANVAS_CENTER_Y + 2.5f, 8.0f, 2.0f, "HELP", []() {  //-------------------------------------------------------------------edw------------------------------------------------
        Game::getInstance()->getScreenManager()->pushScreen(new HelpScreen());
    }));
}

MainMenuScreen* MainMenuScreen::getInstance() {
    if (!m_instance) {
        m_instance = new MainMenuScreen();
    }
    return m_instance;
}

void MainMenuScreen::draw() {
    graphics::Brush br;
    br.outline_opacity = 0.0f;
    br.texture = ASSET_PATH + std::string("raccoonchase.png");       //-------------------------------------------------------------------edw------------------------------------------------
    drawRect(CANVAS_CENTER_X, CANVAS_CENTER_Y, CANVAS_WIDTH, CANVAS_HEIGHT, br);

    for (auto& button : m_buttons) {
        button.draw();
    }
}

void MainMenuScreen::update(float deltaTime) {
    for (auto& button : m_buttons) {
        button.update();
    }
}

void MainMenuScreen::handleInput() {
    for (auto& button : m_buttons) {
        button.handleInput();
    }
}