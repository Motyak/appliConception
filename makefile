CC=g++
CFLAGS=#-O3
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
SRC=src/Model.cpp src/IhmSfml.cpp src/Controller.cpp src/main.cpp
OBJ=obj/Model.o obj/IhmSfml.o obj/Controller.o obj/main.o
EXEC=bin/quixo
DIRS=bin obj

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

obj/Model.o: src/Model.cpp src/Model.h
	$(CC) -c src/Model.cpp -o obj/Model.o $(CFLAGS)

obj/IhmSfml.o: src/IhmSfml.cpp src/IhmSfml.h
	$(CC) -c src/IhmSfml.cpp -o obj/IhmSfml.o $(CFLAGS)

obj/Controller.o: src/Ihm.h src/Controller.cpp src/Controller.h
	$(CC) -c src/Controller.cpp -o obj/Controller.o $(CFLAGS)

obj/main.o: src/main.cpp
	$(CC) -c src/main.cpp -o obj/main.o $(CFLAGS)

clean:
	rm -rf $(OBJ)

mrproper:
	rm -rf $(DIRS)

# will create all necessary directories after the Makefile is parsed
$(shell mkdir -p $(DIRS))