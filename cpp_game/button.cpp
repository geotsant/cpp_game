#include "button.h"
#include "sgg/graphics.h"
#include "define.h"


//Constructor
Button::Button(float x, float y, float width, float height, const std::string& label, std::function<void()> callback)
: m_x(x), m_y(y), m_width(width), m_height(height), m_label(label), m_callback(callback) {
}

void Button::draw() {

    graphics::Brush br;
    if (m_hovered) {
        SETCOLOR(br.fill_color, 0.969f, 0.486f, 0.063f);
    } else {
        SETCOLOR(br.fill_color, 0.969f, 0.839f, 0.063f);
    }
    br.outline_opacity = 1.0f;
    SETCOLOR(br.outline_color, 0.969f, 0.486f, 0.063f);
    drawRect(m_x, m_y, m_width, m_height, br);

    SETCOLOR(br.fill_color, 1.0f, 0.486f, 0.063f)
    graphics::setFont("font.ttf");     //-------------------------------------------------------------------edw------------------------------------------------
    drawText(m_x - m_width / 2 + 0.1f, m_y + 0.2f, 0.5f, m_label, br);
}

void Button::update() {
    graphics::MouseState ms;
    getMouseState(ms);

    float mx = graphics::windowToCanvasX(ms.cur_pos_x);
    float my = graphics::windowToCanvasY(ms.cur_pos_y);

    m_hovered = isHighlighted(mx, my);
    if (m_hovered && ms.button_left_pressed) {
        onClick();
    }
}

void Button::handleInput() {
}

bool Button::isHighlighted(float mx, float my) {
    return mx >= m_x - m_width / 2 && mx <= m_x + m_width / 2 &&
           my >= m_y - m_height / 2 && my <= m_y + m_height / 2;
}

void Button::onClick() {
    if (m_callback) {
        m_callback();
    }
}
