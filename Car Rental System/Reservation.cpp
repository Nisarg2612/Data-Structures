#include "Reservation.hpp"

Reservation::
Reservation(string name, string cRented): name{name}, carRented{cRented}{}

ostream& operator<<(ostream& os, Reservation r){
    os << r.getName() << " rented ["
        << r.getRentedCar() << "]" << endl;
    return os;
}