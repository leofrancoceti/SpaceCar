#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>

int main()
{
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Aceite", sf::Style::Default);
    window.setFramerateLimit(60);

    sf::Texture textureAc;
    if (!textureAc.loadFromFile("./assets/images/Obstaculos/Aceite.png"))
    {
        return -1;
    }

    sf::Sprite spriteAc;
    spriteAc.setTexture(textureAc);
    spriteAc.setPosition(400, 300);
    spriteAc.setColor(sf::Color::Black);

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
        window.draw(spriteAc);
        window.display();
    }

    return EXIT_SUCCESS;
}
