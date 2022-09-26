//
// Created by Gabriel de Taxis on 20/09/2022.
//

#ifndef R_TYPE_PLAYERCONTROLSYSTEM_H
#define R_TYPE_PLAYERCONTROLSYSTEM_H


#include "../Core/System.h"


class Event;


class PlayerControlSystem : public System
{
public:
    void Init();

    void Update(float dt);

private:
    std::bitset<8> mButtons;

    void InputListener(Event& event);
};


#endif //R_TYPE_PLAYERCONTROLSYSTEM_H
