#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Carro
{
private:
    sf::Sprite carro;
    sf::Texture texture;

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
