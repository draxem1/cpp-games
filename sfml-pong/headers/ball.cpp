#include "ball.h"
#include <SFML/Graphics.hpp>

Ball::Ball()
{
    p_ball.setRadius(diameter);
    p_ball.setFillColor(sf::Color(255,255,0,255));
    p_ball.setPosition(sf::Vector2f(init_start[0], init_start[1]));
}

void Ball::move()
{
    if(up_down == false)
        init_start[1] += speed;
    else
        init_start[1] -= speed;
    
    if(init_start[1] <= 5)
        up_down = false;
    if (init_start[1] >= 595)
        up_down = true;

    p_ball.setPosition(sf::Vector2f(init_start[0], init_start[1]));
}