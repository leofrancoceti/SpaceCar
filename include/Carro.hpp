#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Carro
{
private:
    sf::Sprite carro;
    sf::Texture texture;
    float speed;

public:
    Carro(bool isPlayer, float posX, float posY)
    {
        if (!this->texture.loadFromFile("./assets/images/CarRed.png"))
        {
            std::cout << "ERROR::Carro::No se pudo cargar la textura del carro" << std::endl;
        }

        this->carro.setTexture(this->texture);
        this->carro.setPosition(posX, posY);

        // Si es el carro del jugador, establecer una velocidad mayor
        this->speed = isPlayer ? 5.f : 3.f;
    }

    void update(sf::RenderWindow* window)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            this->carro.move(-this->speed, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            this->carro.move(this->speed, 0.f);
        }
    }

    void render(sf::RenderWindow* target)
    {
        target->draw(this->carro);
    }

    sf::FloatRect getBounds() const
    {
        return this->carro.getGlobalBounds();
    }
};
