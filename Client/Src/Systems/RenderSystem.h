//
// Created by Gabriel de Taxis on 20/09/2022.
//

#ifndef R_TYPE_RENDERSYSTEM_H
#define R_TYPE_RENDERSYSTEM_H


#pragma once

#include "../Core/System.h"
#include <memory>


class Event;


class RenderSystem : public System
{
public:
    void Init();

    void Update(float dt);

private:
    void WindowSizeListener(Event& event);

};


#endif //R_TYPE_RENDERSYSTEM_H
