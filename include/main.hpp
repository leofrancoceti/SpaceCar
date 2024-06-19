#include <SFML/Graphics.hpp>
#include "Puntaje.hpp"
#include "Carro.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SpaceCar");
    window.setFramerateLimit(60);

    Puntaje puntaje;
    Carro jugador(true, 400.f, 500.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        jugador.update(&window);

       // incrementar puntaje cada frame
        puntaje.aggPuntuacion(1);

        window.clear();
        jugador.render(&window);
        puntaje.draw(window);
        window.display();
    }

    return 0;
}
