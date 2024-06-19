#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>

int main()
{
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Señal", sf::Style::Default);
    window.setFramerateLimit(60);

    sf::Texture textureSe;
    if (!textureSe.loadFromFile("./assets/images/Obstaculos/Señal.png"))
    {
        return -1;
    }

    sf::Sprite spriteSe;
    spriteSe.setTexture(textureSe);
    spriteSe.setPosition(400, 300);
    spriteSe.setColor(sf::Color::Yellow);

    while (window.isOpen())
    {
        sf::Event eventSe;
        while (window.pollEvent(eventSe))
        {
            switch (eventSe.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }

        window.clear();
        window.draw(spriteSe);
        window.display();
    }

    return EXIT_SUCCESS;
}
