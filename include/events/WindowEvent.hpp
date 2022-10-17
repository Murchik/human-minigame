#pragma once

#include <sstream>

#include "events/Event.hpp"

namespace MyGame {

class WindowCloseEvent : public Event {
   public:
    WindowCloseEvent() {}

    virtual int GetCategoryFlags() const override {
        return EventCategoryWindow;
    }

    virtual EventType GetEventType() const override {
        return EventType::WindowClose;
    }

    virtual const char* GetName() const override { return "WindowClose"; }

    std::string GetNameToString() const override {
        std::stringstream ss;
        ss << "WindowCloseEvent";
        return ss.str();
    }

    static EventType GetEventTypeStatic() { return EventType::WindowClose; }
};

}  // namespace MyGame
