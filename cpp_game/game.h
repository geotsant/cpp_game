#pragma once
#include <list>
#include "event.h"
#include "player.h"
#include "screen_manager.h"


enum GameState { STATE_INIT,
                 STATE_RUNNING,
                 STATE_PAUSED,
                 STATE_EXIT };
class Game {
private:
    static Game* m_instance;
    ScreenManager screenManager;
    GameState currentState;

protected:

    std::list<Player*> m_players;
    std::list<Event*> m_events;

    float m_init_pos_x;
    float m_init_pos_y;
    bool m_valid_action = false;

    Game(){}
public:
    static Game* getInstance();
    static void releaseInstance();
    ScreenManager* getScreenManager();

    void draw();
    void update(float deltaTime) ;
    void handleInput();
    void init();
    void changeState(GameState newState);

    ~Game();

    void processEvents();
    void addEvent(Event* evt);
};