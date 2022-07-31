#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

class Paddle
{
public:
   Paddle(float, float);
   sf::RectangleShape player;
   sf::RectangleShape cpu;
   void movePlayer(sf::Vector2i cord, sf::Vector2f ball_position);
   void moveCpu(sf::Vector2f ball_position);
private:
    const float width = 10; 
    const float height = 80;
    float posX;
    float speed{1.0};
    const int upper_bound = 590;
    const int lower_bound = 10;
    float cpu_start[2]{1150.0, 280.0};
};

#endif