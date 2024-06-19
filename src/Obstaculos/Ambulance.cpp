#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>

int main()
{
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Ambulance", sf::Style::Default);
    window.setFramerateLimit(60);

    sf::Texture textureAm;
    if (!textureAm.loadFromFile("./assets/images/Obstaculos/Ambulance.png"))
    {
        return -1;
    }

    sf::Sprite spriteAm;
    spriteAm.setTexture(textureAm);
    spriteAm.setPosition(400, 300);
    spriteAm.setColor(sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event eventAc;
        while (window.pollEvent(eventAc))
        {
            switch (eventAc.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }

        window.clear();
        window.draw(spriteAm);
        window.display();
    }

    return EXIT_SUCCESS;
}
