#include "game_screen.h"
#include "sgg/graphics.h"
#include "define.h"
#include "button.h"
#include "game.h"
#include "main_menu_screen.h"
#include <iostream>

constexpr float CANVAS_CENTER_X = CANVAS_WIDTH / 2;
constexpr float CANVAS_CENTER_Y = CANVAS_HEIGHT / 2;

GameScreen* GameScreen::m_instance = nullptr;

//constructor with parameter
GameScreen::GameScreen(const char difficulty) : m_difficulty(difficulty) {
    m_buttons.push_back(Button(1.5f, 1.5f, 2.0f, 2.0f, "<-", []() {
        Game::getInstance()->getScreenManager()->pushScreen(new MainMenuScreen());
    }));

    if (m_difficulty == 'e') {
        std::cout << "Game mode = easy\n";
    } else if (m_difficulty == 'm') {
        std::cout << "Game mode = medium\n";
    } else if (m_difficulty == 'h') {
        std::cout << "Game mode = hard\n";
    }
}

GameScreen* GameScreen::getInstance(char difficulty) {
    if (!m_instance) {
        m_instance = new GameScreen(difficulty);
    }
    return m_instance;
}

void GameScreen::draw() {
    graphics::Brush br;
    br.outline_opacity = 0.0f;
    //br.texture = ASSET_PATH + std::string("raccoon-chase.png");
    drawRect(CANVAS_CENTER_X, CANVAS_CENTER_Y, CANVAS_WIDTH, CANVAS_HEIGHT, br);

    for (auto& button : m_buttons) {
        button.draw();
    }
}

void GameScreen::update(float deltaTime) {
    for (auto& button : m_buttons) {
        button.update();
    }
}

void GameScreen::handleInput() {
    for (auto& button : m_buttons) {
        button.handleInput();
    }
}
