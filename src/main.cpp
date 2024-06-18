#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
//#include <time.h>
// Se puede incluir en juego del carro nani (en observaciones)#include <Game.hpp>
//

int main()
{
    srand(time(static_cast<unsigned>(0)));

    Game game;

    while (game.running()) 
    {

        // Update
        game.update();

        // Render
        game.render();
    }

    return 0;
}