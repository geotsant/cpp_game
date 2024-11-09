#include "game.h"
#include "sgg/graphics.h"
#include "define.h"
#include "main_menu_screen.h"
#include <iostream>

Game* Game::m_instance = nullptr;

Game * Game::getInstance() {
    if (!m_instance) {
        m_instance = new Game();
    }
    return m_instance;
}

void Game::releaseInstance() {
    delete m_instance;
    m_instance = nullptr;
}

ScreenManager* Game::getScreenManager() {
    return &screenManager;
}

void Game::draw() {
    if (currentState == STATE_RUNNING) {
        screenManager.draw();
    }
}

void Game::update(float deltaTime) {
    if (currentState == STATE_RUNNING) {
        screenManager.update(deltaTime);
    }
}

void Game::handleInput() {
    if (currentState == STATE_RUNNING) {
        screenManager.handleInput();
    }
}

void Game::init() {
    currentState = STATE_INIT;

    graphics::preloadBitmaps(ASSET_PATH);
    /*
    if (graphics::preloadBitmaps(ASSET_PATH).data()) {
        std::cout << "Assets preloaded successfully." << std::endl;
    } else {
        std::cout << "Failed to preload assets." << std::endl;
    }
    */

    screenManager.pushScreen(new MainMenuScreen());
    changeState(STATE_RUNNING);
}

void Game::changeState(GameState newState) {
    currentState = newState;
}

Game::~Game() {
    //-------------needs something?
}


//--------about events
void Game::processEvents() {
    for (auto e : m_events) {
        e->update();
    }
    m_events.remove_if([](Event* ev) {
        return !ev->active();
    });
}

void Game::addEvent(Event *evt) {
    m_events.push_front(evt);
}

//Game* Game::m_instance = nullptr;