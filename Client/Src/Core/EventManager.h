//
// Created by Gabriel de Taxis on 20/09/2022.
//

#ifndef R_TYPE_EVENTMANAGER_H
#define R_TYPE_EVENTMANAGER_H

#include "Event.h"
#include "Types.h"
#include <functional>
#include <list>
#include <unordered_map>


class EventManager
{
public:
    void AddListener(EventId eventId, std::function<void(Event&)> const& listener)
    {
        listeners[eventId].push_back(listener);
    }

    void SendEvent(Event& event)
    {
        uint32_t type = event.GetType();

        for (auto const& listener : listeners[type])
        {
            listener(event);
        }
        std::cout << "received event => " << event.GetType() << std::endl;
    }

    void SendEvent(EventId eventId)
    {
        Event event(eventId);

        for (auto const& listener : listeners[eventId])
        {
            listener(event);
        }
        std::cout << "received eventId => " << eventId << std::endl;
    }

private:
    std::unordered_map<EventId, std::list<std::function<void(Event&)>>> listeners;
};


#endif //R_TYPE_EVENTMANAGER_H
