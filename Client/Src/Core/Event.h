//
// Created by Gabriel de Taxis on 20/09/2022.
//

#ifndef R_TYPE_EVENT_H
#define R_TYPE_EVENT_H

#include "Types.h"
#include <any>
#include <unordered_map>


class Event
{
public:
    Event() = delete;

    explicit Event(EventId type)
            : mType(type)
    {}

    template<typename T>
    void SetParam(EventId id, T value)
    {
        mData[id] = value;
    }

    template<typename T>
    T GetParam(EventId id)
    {

        return std::any_cast<T>(mData[id]);
    }

    EventId GetType() const
    {
        return mType;
    }

private:
    EventId mType{};
    std::unordered_map<EventId, std::any> mData{};
};


#endif //R_TYPE_EVENT_H
