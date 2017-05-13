all:
	g++ cube.cpp -IC:/MinGW/include/SDL2 -LC:/MinGW/lib/ -w -lmingw32 -lSDL2main -lSDL2 -o cube 
out:
	./cube
