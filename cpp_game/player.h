#pragma once

class Player {
    float m_pos[2];

public:
    void draw();
    void update();
    Player();

    float getPosX() {return m_pos[0];}
    float getPosY(){return m_pos[1];}

    void setPosX(float x) {m_pos[0] = x;}
    void setPosY(float y) {m_pos[1] = y;}

    bool intersect(Player * tgt);
};