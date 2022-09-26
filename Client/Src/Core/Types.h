//
// Created by Gabriel de Taxis on 20/09/2022.
//

#ifndef R_TYPE_TYPES_H
#define R_TYPE_TYPES_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>
#include <array>
#include <cassert>
#include <bitset>
#include <cstdint>
#include <unordered_map>
#include <string>
#include <set>

// ECS
using Entity = std::uint32_t;
const Entity MAX_ENTITIES = 5000;
using ComponentType = std::uint8_t;
const ComponentType MAX_COMPONENTS = 32;
using Signature = std::bitset<MAX_COMPONENTS>;

using EventId = std::uint32_t;
using ParamId = std::uint32_t;

enum class InputButtons
{
    W,
    A,
    S,
    D,
    Q,
    E
};

// Source: https://gist.github.com/Lee-R/3839813
constexpr std::uint32_t fnv1a_32(char const* s, std::size_t count)
{
    return ((count ? fnv1a_32(s, count - 1) : 2166136261u) ^ s[count]) * 16777619u; // NOLINT (hicpp-signed-bitwise)
}

constexpr std::uint32_t operator "" _hash(char const* s, std::size_t count)
{
    return fnv1a_32(s, count);
}

#define METHOD_LISTENER(EventType, Listener) EventType, std::bind(&Listener, this, std::placeholders::_1)
#define FUNCTION_LISTENER(EventType, Listener) EventType, std::bind(&Listener, std::placeholders::_1)

namespace Events::Window {
    const EventId QUIT = "Events::Window::QUIT"_hash;
    const EventId RESIZED = "Events::Window::RESIZED"_hash;
    const EventId INPUT = "Events::Window::INPUT"_hash;
}

namespace Events::Window::Input {
    const ParamId INPUT = "Events::Window::Input::INPUT"_hash;
}

namespace Events::Window::Resized {
    const ParamId WIDTH = "Events::Window::Resized::WIDTH"_hash;
    const ParamId HEIGHT = "Events::Window::Resized::HEIGHT"_hash;
}


#endif //R_TYPE_TYPES_H
