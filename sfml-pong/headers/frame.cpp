#include "frame.h"
#include "paddle.h"
#include "ball.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>

Frame::Frame()
{
    width = 1200;
    height = 600;
}

void Frame::init()
{
    sf::RenderWindow window(sf::VideoMode(width,height),"PONG!");
    Paddle box(40.0,280.0);
    Ball ball;

    while (window.isOpen())
    {
        window.setMouseCursorVisible(false);
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        events(window, box, ball);
        window.draw(box.player);
        window.draw(box.cpu);
        window.draw(ball.p_ball);
        window.display();
    }
}

//Moves Ball and Paddle at same time 
//Multi-threading
void Frame::events(sf::RenderWindow& window, Paddle& player, Ball& ball)
{
    sf::Vector2i position = sf::Mouse::getPosition(window);
    sf::Vector2f computer = ball.p_ball.getPosition();
    std::thread worker1(&Paddle::movePlayer, &player, position, computer);
    std::thread worker2(&Ball::move, &ball);

    worker1.join();
    worker2.join();
}