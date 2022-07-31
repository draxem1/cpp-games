#ifndef FRAME_H 
#define FRAME_H 
#include "paddle.h"
#include "ball.h"
#include <SFML/Graphics.hpp>

class Frame
{
public: 
    Frame();
    void init();
private:    
    int width;
    int height;
    void events(sf::RenderWindow& window, Paddle& player, Ball& ball);
};
#endif