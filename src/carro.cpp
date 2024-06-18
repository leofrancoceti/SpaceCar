#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>

int main()
{
   //oculta ventana
    ShowWindow(GetConsoleWindow(), SW_HIDE); 

    // creacion de v para visualizar carro
    sf::RenderWindow window(sf::VideoMode(800, 600), "Carro", sf::Style::Default);
    window.setFramerateLimit(60); // Limita la cantidad de frames por segundo a 60.

    // Text de CARRO
    sf::Texture textureN;
    if (!textureN.loadFromFile("./assets/images/CarRed.png"))
    {
        return -1; 
    }
    sf::Sprite spriteN;               
    spriteN.setTexture(textureN);     
    spriteN.setPosition(400, 300);    
    spriteN.setColor(sf::Color::Red); 

    while (window.isOpen())
    {
        sf::Event eventN;
        while (window.pollEvent(eventN))
        {
            switch (eventN.type)
            {
            case sf::Event::Closed: 
                window.close();
                break;
            default:
                break;
            }
        }

        window.clear();
        window.draw(spriteN);
        window.display();
    }

    return EXIT_SUCCESS;
}