bin/draw : src/dibujo_test.cpp
	g++ src/dibujo_test.cpp -o bin/draw -I include -l ftxui-screen -l ftxui-dom -l ftxui-component -std=c++2a

run : bin/draw
	./bin/draw