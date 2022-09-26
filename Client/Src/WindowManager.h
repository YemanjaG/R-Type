//
// Created by Gabriel de Taxis on 20/09/2022.
//

#ifndef R_TYPE_WINDOWMANAGER_H
#define R_TYPE_WINDOWMANAGER_H

#include "Core/Types.h"
#include <bitset>
#include <string>
#include <iostream>


class WindowManager
{
public:
    void Init(std::string const& windowTitle, int windowWidth, int windowHeight);
    void Update();
    void ProcessEvents();
    void Shutdown();

    sf::RenderWindow mWindow;

private:
    std::bitset<8> mButtons;

};



#endif //R_TYPE_WINDOWMANAGER_H
