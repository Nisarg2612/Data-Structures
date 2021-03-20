CC=g++
CFLAGS=-std=c++11

default: main

main: main.o Car.o CarLinkedList.o enums.o Menu.o Reservation.o ReservationArrayList.o 
	$(CC) $(CFLAGS) -o program main.o Car.o CarLinkedList.o enums.o Menu.o Reservation.o ReservationArrayList.o

main.o: main.cpp 
	$(CC) -c $(CFLAGS) main.cpp

Car.o: Car.cpp
	$(CC) -c $(CFLAGS) Car.cpp

CarLinkedList.o: CarLinkedList.cpp
	$(CC) -c $(CFLAGS) CarLinkedList.cpp

enums.o: enums.cpp
	$(CC) -c $(CFLAGS) enums.cpp

Menu.o: Menu.cpp
	$(CC) -c $(CFLAGS) Menu.cpp

Reservation.o: Reservation.cpp
	$(CC) -c $(CFLAGS) Reservation.cpp

ReservationArrayList.o: ReservationArrayList.cpp
	$(CC) -c $(CFLAGS) ReservationArrayList.cpp

clean: 
	rm -rf ./*.o 
	rm -rf ./program
