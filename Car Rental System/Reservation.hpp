#ifndef Reservation_hpp
#define Reservation_hpp

#include <iostream>
#include <string>
#include "enums.hpp"

using namespace std;

class Reservation{
private:
    string name;
    string carRented;
public:
    Reservation(): name{""}, carRented{""}{};
    Reservation(string name, string cRented);
    string getName(){ return name;}
    string getRentedCar(){ return carRented;}
    Relation CompareTo(Reservation other){
        if(carRented < other.getRentedCar())
            return Relation::LT;
        else if (carRented == other.getRentedCar())
            return Relation::EQ;
        return Relation::GT;
    }
};

ostream& operator<<(ostream& os, Reservation r);

#endif /* Reservation_hpp */