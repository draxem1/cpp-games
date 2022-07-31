#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball
{
public:
    Ball();
    sf::CircleShape p_ball;
    void move();
private:
    float diameter{6.0};
    float init_start[2]{600.0, 280.0};
    float speed = 0.05;
    bool up_down = false;
    bool left_right = false;
};

#endif 