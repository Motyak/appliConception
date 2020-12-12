CC=g++
CFLAGS=#-O3
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
SRC=src/Model.cpp src/IhmSfml.cpp src/Random.cpp src/Controller.cpp src/main.cpp
OBJ=obj/Model.o obj/Ihm.o obj/IhmSfml.o obj/Random.o obj/Controller.o obj/main.o
EXEC=bin/quixo
DIRS=bin obj

all: prep release

release: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

obj/Model.o: src/Model.cpp src/Model.h
	$(CC) -c $< -o $@ $(CFLAGS)

obj/Ihm.o: src/Ihm.cpp src/Ihm.h
	$(CC) -c $< -o $@ $(CFLAGS)

obj/IhmSfml.o: src/IhmSfml.cpp src/IhmSfml.h
	$(CC) -c $< -o $@ $(CFLAGS)

obj/Random.o: src/Random.cpp src/Random.h src/Ai.h
	$(CC) -c $< -o $@ $(CFLAGS)

obj/Controller.o: src/Controller.cpp src/Controller.h
	$(CC) -c $< -o $@ $(CFLAGS)

obj/main.o: src/main.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

debug: CFLAGS += -g
debug: clean all

prep:
	@mkdir -p $(DIRS)

remake: clean all

clean:
	rm -f $(OBJ)

mrproper:
	rm -rf $(DIRS)
