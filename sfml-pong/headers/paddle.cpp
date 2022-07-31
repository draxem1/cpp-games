#include "paddle.h"
#include <SFML/Graphics.hpp>

Paddle::Paddle(float x, float y)
{
    posX = x;
    player.setSize(sf::Vector2f(width, height));
    player.setFillColor(sf::Color(250,255,0,255));
    player.setPosition(posX, y);

    cpu.setSize(sf::Vector2f(width, height));
    cpu.setFillColor(sf::Color(250,255,0,255));
    cpu.setPosition(cpu_start[0], cpu_start[1]);
}

void Paddle::movePlayer(sf::Vector2i cord, sf::Vector2f ball_position)
{
    if (cord.y <= lower_bound)
        cord.y = lower_bound;
    if (cord.y >= (upper_bound - height))
        cord.y = upper_bound - height;

    player.setPosition(posX,cord.y);

    moveCpu(ball_position);
}

void Paddle::moveCpu(sf::Vector2f ball_position)
{
    sf::Vector2f cpu_paddle_position = cpu.getPosition();

    if(ball_position.y > cpu_paddle_position.y)
        cpu_start[1] += speed;
    if(ball_position.y < cpu_paddle_position.y)
        cpu_start[1] -= speed;
    
    cpu.setPosition(cpu_start[0], cpu_start[1]);
}
