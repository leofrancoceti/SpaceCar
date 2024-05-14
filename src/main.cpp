#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <experimental/random>
#include <list>
#include <fstream>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    fstream imagen;
    list<string> textos;
    string linea;

    fstream imagen2;
    list<string> textos2;
    string linea2;

    imagen.open("./assets/Carro.txt");

    while (getline(imagen, linea))
    {
        textos.push_back(linea);
    }
    imagen.close();

    imagen2.open("./assets/Caja.txt");

    while (getline(imagen2, linea2))
    {
        textos2.push_back(linea2);
    }
    imagen2.close();

    int posX = 2;
    int posY = 8;

    int posX_C = 130;
    int posY_C = 8;

    int fotograma = 0;
    string reset;

    int AltoI = 22;

    while (true)
    {
        fotograma++;

        // Color de fondo
        int R = 236;
        int G = 226;
        int B = 198;

        Element personaje = spinner(21, fotograma);
        Decorator colorFondo = bgcolor(Color::RGB(R, G, B));
        Decorator colorTexto = color(Color::RGB(B, G, R));
        Element dibujo = border({hbox() | colorFondo | colorTexto});

        // Crear dimensiones de pantalla
        Dimensions Alto = Dimension::Fixed(AltoI);
        Dimensions Ancho = Dimension::Full();

        // Crear pantalla
        Screen pantalla = Screen::Create(Ancho, Alto);

        // Imprimir en la pantalla
        Render(pantalla, dibujo);

        int l = 0;
        for (auto &&texto : textos)
        {
            int i = 0;
            for (auto &&letra : texto)
            {
                pantalla.PixelAt(posX + i, posY + l).character = letra;
                i++;
            }
            l++;
        }

        pantalla.Print();

        int x = 0;
        for (auto &&texto2 : textos2)
        {
            int y = 0; 
            for (auto &&letra2 : texto2)
            {
                pantalla.PixelAt(posX_C + x, posY_C + y).character = letra2;
                y++; 
            }
            x++;
        }

        posX_C --;
        pantalla.Print();

        
        reset = pantalla.ResetPosition();
        cout << reset;
        this_thread::sleep_for(0.1s);
    }

    return 0;
}