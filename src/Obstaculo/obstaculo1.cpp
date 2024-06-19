#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>

int main()
{
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Obstaculo1", sf::Style::Default);
    window.setFramerateLimit(60);

    sf::Texture textureCar;
    if (!textureCar.loadFromFile("./assets/images/Car/CarRed.png"))
    {
        return -1;
    }

    sf::Sprite spriteCar;
    spriteCar.setTexture(textureCar);
    spriteCar.setPosition(400, 500);

    sf::Texture textureObstacle;
    if (!textureObstacle.loadFromFile("./assets/images/Obstaculos/Ambulance.png"))
    {
        return -1;
    }

    sf::Sprite spriteObstacle;
    spriteObstacle.setTexture(textureObstacle);
    spriteObstacle.setPosition(400, -100);

    float speed = 5.0f;
    float obstacleSpeed = 3.0f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (spriteCar.getPosition().x > 0)
            {
                spriteCar.move(-speed, 0);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (spriteCar.getPosition().x + spriteCar.getGlobalBounds().width < window.getSize().x)
            {
                spriteCar.move(speed, 0);
            }
        }

        spriteObstacle.move(0, obstacleSpeed);
        if (spriteObstacle.getPosition().y > window.getSize().y)
        {
            spriteObstacle.setPosition(rand() % (window.getSize().x - (int)spriteObstacle.getGlobalBounds().width), -100);
        }

        if (spriteCar.getGlobalBounds().intersects(spriteObstacle.getGlobalBounds()))
        {
            // Handle collision (restart game, reduce life, etc.)
            window.close();
        }

        window.clear();
        window.draw(spriteCar);
        window.draw(spriteObstacle);
        window.display();
    }

    return EXIT_SUCCESS;
}
//g