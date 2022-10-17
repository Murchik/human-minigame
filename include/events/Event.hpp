#pragma once

#include <functional>
#include <string>

#define BIT(x) 1 << x

namespace MyGame {

enum class EventType {
    None = 0,
    WindowClose,
    WindowResize,
    KeyPressed,
    KeyReleased,
    MouseButtonPressed,
    MouseButtonReleased
};

enum EventCategory {
    None = 0,
    EventCategoryWindow = BIT(1),
    EventCategoryInput = BIT(2),
    EventCategoryKeyboard = BIT(3),
    EventCategoryMouse = BIT(4)
};

class Event {
    friend class EventDispatcher;

   public:
    virtual EventType GetEventType() const = 0;
    virtual int GetCategoryFlags() const = 0;
    virtual const char* GetName() const = 0;
    virtual std::string GetNameToString() const { return GetName(); }

    inline bool IsInCategory(EventCategory category) {
        return GetCategoryFlags() & category;
    }

   protected:
    bool m_Handeled = false;
};

class EventDispatcher {
    template <typename T>
    using EventFunc = std::function<bool(T&)>;

   public:
    EventDispatcher(Event& event) : m_Event(event) {}

    template <typename T>
    bool Dispatch(EventFunc<T> func) {
        if (m_Event.GetEventType() == T::GetEventTypeStatic()) {
            m_Event.m_Handeled = func(*(T*)&m_Event);
            return true;
        }
        return false;
    }

   private:
    Event& m_Event;
};

}  // namespace MyGame
