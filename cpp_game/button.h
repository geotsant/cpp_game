#pragma once
#include <functional>
#include <string>

/*
Properties: x, y, width, height, label, callback, etc.
Methods: draw(), update(), handleInput(), isHovered(), onClick(), etc.
*/


class Button {
public:
    Button(float x, float y, float width, float height, const std::string& label, std::function<void()> callback);

    void draw();
    void update();
    void handleInput();

private:
    float m_x, m_y, m_width, m_height;
    std::string m_label;
    std::function<void()> m_callback;
    bool m_hovered = false;

    bool isHighlighted(float mx, float my);
    void onClick();
};