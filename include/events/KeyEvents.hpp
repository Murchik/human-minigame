#pragma once

#include <sstream>

#include "events/Event.hpp"

namespace MyGame {

class KeyEvent : public Event {
   public:
    inline int GetKeyCode() const { return m_KeyCode; }

    virtual int GetCategoryFlags() const override {
        return EventCategoryKeyboard | EventCategoryInput;
    }

   protected:
    KeyEvent(int keyCode) : m_KeyCode(keyCode) {}
    int m_KeyCode;
};

class KeyPressedEvent : public KeyEvent {
   public:
    KeyPressedEvent(int keyCode) : KeyEvent(keyCode) {}

    virtual EventType GetEventType() const override {
        return EventType::KeyPressed;
    }

    virtual const char* GetName() const override { return "KeyPressed"; }

    std::string GetNameToString() const override {
        std::stringstream ss;
        ss << "KeyPressedEvent: " << m_KeyCode;
        return ss.str();
    }

    static EventType GetEventTypeStatic() { return EventType::KeyPressed; }
};

class KeyReleasedEvent : public KeyEvent {
   public:
    KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}

    virtual EventType GetEventType() const override {
        return EventType::KeyReleased;
    }

    virtual const char* GetName() const override { return "KeyReleased"; }

    std::string GetNameToString() const override {
        std::stringstream ss;
        ss << "KeyReleasedEvent: " << m_KeyCode;
        return ss.str();
    }

    static EventType GetEventTypeStatic() { return EventType::KeyReleased; }
};

}  // namespace MyGame
