#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Carro
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::SoundBuffer buffer;
    sf::Sound crashSound;
    int hitCount;

    void initVariables()
    {
        this->hitCount = 0;
        this->scaleX = 1.0f;
        this->scaleY = 1.0f;
    }

    void initTexture()
    {
        if (!this->texture.loadFromFile("./assets/images/Ostaculos/Ambulance.png"))
        {
            std::cout << "ERROR::Carro::initTexture::No se pudo cargar la textura del obstáculo" << std::endl;
        }
    }

    void initSprite()
    {
        this->sprite.setTexture(this->texture);
        this->sprite.scale(this->scaleX, this->scaleY);
    }

    void initSound()
    {
        if (!this->buffer.loadFromFile("./Music/Car Racing Game MOO ICT_Resources_hit.wav"))
        {
            std::cout << "ERROR::Carro::initSound::No se pudo cargar el sonido de choque" << std::endl;
        }
        this->crashSound.setBuffer(this->buffer);
    }

public:
    Carro(float posX = 0.f, float posY = 0.f)
    {
        this->initVariables();
        this->initTexture();
        this->initSprite();
        this->initSound();
        this->sprite.setPosition(posX, posY);
    }

    ~Carro() {}

    void playCrashSound()
    {
        this->crashSound.play();
    }

    void takeHit()
    {
        this->hitCount++;
    }

    int getHitCount() const
    {
        return this->hitCount;
    }

    sf::Sprite& getSprite()
    {
        return this->sprite;
    }
};
//g