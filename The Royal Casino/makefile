CC=g++
CFLAGS=-std=c++11

default: Game

Game: Game.o Reel.o SlotMachine.o  
	$(CC) $(CFLAGS) -o program Game.o Reel.o SlotMachine.o

Game.o: Game.cpp 
	$(CC) -c $(CFLAGS) Game.cpp

Reel.o: Reel.cpp
	$(CC) -c $(CFLAGS) Reel.cpp

SlotMachine.o: SlotMachine.cpp
	$(CC) -c $(CFLAGS) SlotMachine.cpp

clean: 
	rm -rf ./*.o 
	rm -rf ./program
