# SpaceCar
![Portada SpaceCar](https://media.istockphoto.com/id/1458751063/es/v%C3%ADdeo/video-animado-de-un-viejo-juego-de-carreras-de-autos-en-estilo-de-8-bits-arcade-pixel-arte-2d.jpg?s=256x256&k=20&c=4nPw4tbcSQUcgEGgQPnJlvN_M_QtPhKdN-oDUs__0fU=)
___
El proyecto tiene como objetivo desarrollar un videojuego basado en texto, utilizando arte ASCII, que tomamos de inspiracion de los ya clasicos juegos de autos arcade.

* Implementar un sistema de juego que permita al jugador controlar un aautomovil y con este poder esquivar diferentes obstaculos que se encontrara en el camino.
* Diseñar este juego de tal manera que mediante el jugador vaya progrsando en tiempo este sea mas rapido y mas complicado.
* Agregar diferentes obstaculos al jugador para que este tenga que mejorar sus ahabilidades en este juego si es que quiere romper su marca personal.

## **Carpetas**
___
El proyecto sigue una estructura organizada en varias carpetas para una gestión eficiente de los archivos y recursos del juego.

* src/: Contiene los archivos fuente del juego, incluido el archivo principal main.cpp que maneja la lógica del juego.

* include/: Contiene archivos de cabecera que definen clases, funciones y estructuras de datos utilizadas en el juego.

* assets/: Aquí se almacenan los recursos del juego, como el arte ASCII para el auto del jugador, los ostaculos , efectos de sonido, etc.

* docs/: Contiene documentación relevante del proyecto, como diagramas UML, especificaciones de diseño y otros documentos.

* README.md: Un archivo de markdown que proporciona una descripción general del proyecto, instrucciones de instalación, ejecución y cualquier otra información relevante.

## **Desarrollo**
___
El juego se desarrollará utilizando C++ junto con la biblioteca FTXUI para crear la interfaz de usuario basada en texto. Se implementará la mecánica principal del los juegos arcade, que en estos esta principalmente el movimiento en 2D del jugador,  la aparición de obstaculos como cajas y charcos de aceite, así como la lógica de colisiones.

La representación visual del juego se realizará utilizando arte ASCII, con archivos de texto dedicados para el auto del jugador, la pista y los obstaculos. 

# Dependencias

## **GraphViz**
___
~~~
sudo apt update

sudo apt install graphviz
~~~

## **FTXUI**
___
~~~
git clone [link:]https://github.com/ArthurSonzogni/FTXUI.git
sudo apt install cmake
cd FTXUI
mkdir build
cd build
cmake ..
make
sudo make install
~~~

## **Plugins VSCode**
___

* material icon
* c/c++
* plant uml
* cmake
* cmake tools
* make file tools