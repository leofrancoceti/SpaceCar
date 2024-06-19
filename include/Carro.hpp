#pragma once
#include <SFML/Graphics.hpp>
<<<<<<< HEAD
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
=======
>>>>>>> c504e9b822ddf21b151d625e88b7fc6c26ebaee9
#include <iostream>

class Carro
{
private:
    sf::Sprite carro;
    sf::Texture texture;
<<<<<<< HEAD

    sf::SoundBuffer buffer;

    double speed;
public:
    void innitTexture()
    {
        if (!this->texture.loadFromFile("./assets/images/Car/CarRed.png"))
        {
            std::cout << "ERROR::Nave::innitTexture::No se pudo cargar la textura de la nave" << std::endl;
        }
    }

    void innitSprite()
    {
        this->carro.setTexture(this->texture);

        this->carro.scale(0.1,0.1);
    }

    void updateInput()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            this->carro.move(-this->speed, 0.f);
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            this->carro.move(this->speed, 0.f);
        } 
    }

    void updateBoundCollsion(const sf::RenderTarget *target)
    {
        


        // Derecha

    }
    Carro(/* args */);
    ~Carro();
};

Carro::Carro(/* args */)
{
}

Carro::~Carro()
{
}
=======
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
>>>>>>> c504e9b822ddf21b151d625e88b7fc6c26ebaee9
