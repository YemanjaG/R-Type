//
// Created by Gabriel de Taxis on 20/09/2022.
//

#ifndef R_TYPE_RENDERABLE_H
#define R_TYPE_RENDERABLE_H

#include <SFML/Graphics.hpp>

struct Renderable{
    sf::Sprite sprite;
    sf::Texture texture;
    int pixToCycle;
};

#endif //R_TYPE_RENDERABLE_H
