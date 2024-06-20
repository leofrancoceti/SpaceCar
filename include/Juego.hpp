#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>

// Clase Carro
class Carro {
private:
    sf::Sprite carro;
    sf::Texture texture;
    double speed;

public:
    Carro(bool isPlayer, float posX, float posY) {
        if (!this->texture.loadFromFile("./assets/images/Car/CarRed.png")) {
            std::cout << "ERROR::Carro::No se pudo cargar la textura del carro" << std::endl;
        }

        this->carro.setTexture(this->texture);
        this->carro.setPosition(posX, posY);

        // Si es el carro del jugador, establecer una velocidad mayor
        this->speed = isPlayer ? 5.f : 3.f;
    }

    void update(sf::RenderWindow* window) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            this->carro.move(-this->speed, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            this->carro.move(this->speed, 0.f);
        }
    }

    void render(sf::RenderWindow* target) {
        target->draw(this->carro);
    }

    sf::FloatRect getBounds() const {
        return this->carro.getGlobalBounds();
    }
};

// Clase Jugador
class Jugador : public Carro {
public:
    Jugador(float posX, float posY) : Carro(true, posX, posY) {}
};

// Clase Obstaculo
class Obstaculo {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::SoundBuffer buffer;
    sf::Sound crashSound;
    int hitCount;
    float scaleX;
    float scaleY;

    void initVariables() {
        this->hitCount = 0;
        this->scaleX = 1.0f;
        this->scaleY = 1.0f;
    }

    void initTexture() {
        if (!this->texture.loadFromFile("./assets/images/Obstaculos/Ambulance.png")) {
            std::cout << "ERROR::Obstaculo::initTexture::No se pudo cargar la textura del obstáculo" << std::endl;
        }
    }

    void initSprite() {
        this->sprite.setTexture(this->texture);
        this->sprite.scale(this->scaleX, this->scaleY);
    }

    void initSound() {
        if (!this->buffer.loadFromFile("./assets/sounds/hit.wav")) {
            std::cout << "ERROR::Obstaculo::initSound::No se pudo cargar el sonido de choque" << std::endl;
        }
        this->crashSound.setBuffer(this->buffer);
    }

public:
    Obstaculo(float posX = 0.f, float posY = 0.f) {
        this->initVariables();
        this->initTexture();
        this->initSprite();
        this->initSound();
        this->sprite.setPosition(posX, posY);
    }

    ~Obstaculo() {}

    void playCrashSound() {
        this->crashSound.play();
    }

    void takeHit() {
        this->hitCount++;
    }

    int getHitCount() const {
        return this->hitCount;
    }

    sf::Sprite& getSprite() {
        return this->sprite;
    }
};

// Clase Puntaje
class Puntaje {
private:
    sf::Font font;
    sf::Text puntajeText;
    int puntaje;

public:
    Puntaje() {
        if (!font.loadFromFile("./assets/fonts/arial.ttf")) {
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

    void aggPuntuacion(int puntos) {
        puntaje += puntos;
        updateText();
    }

    void updateText() {
        puntajeText.setString("Puntaje: " + std::to_string(puntaje));
    }

    void draw(sf::RenderWindow &window) {
        window.draw(puntajeText);
    }

    int getPuntaje() const {
        return puntaje;
    }

    void resetPuntaje() {
        puntaje = 0;
        updateText();
    }
};

// Clase Juego
class Juego {
private:
    sf::RenderWindow* window;
    Jugador* jugador;
    std::vector<Obstaculo> obstaculos;
    Puntaje* puntaje;

    void initWindow() {
        this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Car Racing Game", sf::Style::Titlebar | sf::Style::Close);
    }

    void initJugador() {
        this->jugador = new Jugador(400.f, 500.f);
    }

    void initObstaculos() {
        this->obstaculos.push_back(Obstaculo(100.f, 100.f));
        this->obstaculos.push_back(Obstaculo(300.f, 200.f));
        this->obstaculos.push_back(Obstaculo(500.f, 300.f));
    }

    void initPuntaje() {
        this->puntaje = new Puntaje();
    }

public:
    Juego() {
        this->initWindow();
        this->initJugador();
        this->initObstaculos();
        this->initPuntaje();
    }

    ~Juego() {
        delete this->window;
        delete this->jugador;
        delete this->puntaje;
    }

    void update() {
        this->jugador->update(this->window);
        
        // Check collisions
        for (auto &obstaculo : this->obstaculos) {
            if (this->jugador->getBounds().intersects(obstaculo.getSprite().getGlobalBounds())) {
                obstaculo.playCrashSound();
                obstaculo.takeHit();
                this->puntaje->aggPuntuacion(-10); // Pérdida de puntos al chocar
            }
        }
    }

    void render() {
        this->window->clear();

        this->jugador->render(this->window);

        for (auto &obstaculo : this->obstaculos) {
            this->window->draw(obstaculo.getSprite());
        }

        this->puntaje->draw(*this->window);

        this->window->display();
    }

    void run() {
        while (this->window->isOpen()) {
            sf::Event event;
            while (this->window->pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    this->window->close();
                }
            }

            this->update();
            this->render();
        }
    }
};
