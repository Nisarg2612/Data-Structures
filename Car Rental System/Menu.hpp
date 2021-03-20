#ifndef Menu_hpp
#define Menu_hpp

#include "Car.hpp"
#include "CarLinkedList.hpp"
#include "Reservation.hpp"
#include "ReservationArrayList.hpp"

class Menu
{
public:
    void runMenu();
    void printMenu();
    void ListCars();
    void addCar();
    void removeCar();
    void ListRes();
    void addRes();
    void cancelRes();
};

#endif /* Menu_hpp */