#pragma once

class Event {
protected:
    float m_pos_x;
    float m_pos_y;

    float m_duration = 2.0f;
    float m_delay = 0.0f;
    float m_elapsed_time = 0.0f;
    float m_elapsed_delay = 0.0f;

    bool m_active = true;
public:
    virtual void draw(){}
    virtual void update();

    virtual ~Event(){}
    bool active() { return m_active; }
};

class RunningEvent : public Event {
    float m_orientation;
    float m_scale;

public:
    void draw() override;
    RunningEvent(float x , float y);
};

