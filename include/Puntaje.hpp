#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream>

class Puntaje
{
private:
    sf::Font font;
    sf::Text puntajeText;
    int puntaje;

public:
    Puntaje()
    {
        if (!font.loadFromFile("./assets/images/bg.png"))
        {
            std::cout << "ERROR::Puntaje::Puntaje::No se pudo cargar la fuente" << std::endl;
        }

        puntaje = 0;
        puntajeText.setFont(font);
        puntajeText.setCharacterSize(22);
        puntajeText.setFillColor(sf::Color::White);
        puntajeText.setPosition(10.f, 10.f);

        updateText();
    }
~Puntaje() {}

    void aggPuntuacion(int puntos)
    {
        puntaje += puntos;
        updateText();
    }

    void updateText()
    {
        puntajeText.setString("Puntaje: " + std::to_string(puntaje));
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(puntajeText);
    }

    int getPuntaje() const
    {
        return puntaje;
    }

    void resetPuntaje()
    {
        puntaje = 0;
        updateText();
    }
};