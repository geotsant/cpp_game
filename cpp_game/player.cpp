#include "player.h"
#include "sgg/graphics.h"
#include "define.h"

void Player::draw() {
    graphics::Brush br;
    SETCOLOR(br.fill_color, 1.0f, 1.0f ,1.0f)
    br.outline_opacity = 0.0f;
    br.fill_opacity = 0.0f;
    drawDisk(m_pos[0], m_pos[1], PLAYER_SIZE , br);
    br.fill_opacity = 1.0f;
    br.texture = ASSET_PATH + std::string("raccoon.png");

}

void Player::update() {}

Player::Player(){}
