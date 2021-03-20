#ifndef Car_hpp
#define Car_hpp

#include "enums.hpp"
#include <iostream>
#include <string>
using namespace std;

extern const char *typeNames[5];

class Car
{
protected:
    string plateNumber;
    string make;
    string model;
    vehicleType vType;
    double PricePerDay;
    bool isAvailable = false;

public:
    Car() : plateNumber{""}, make{""}, model{""}, vType(), PricePerDay{0},
            isAvailable{true} {}
    Car(string plateNumber, string make, string model, vehicleType vType, double ppd,
        bool isAvailable);
    ostream &print(ostream & os);
    string getPlateNumber() { return plateNumber; }
    string getMake() { return make; }
    string getModel() { return model; }
    vehicleType getVehicleType() { return vType; }
    double getPricePerDay() { return PricePerDay; }
    void setAvailable(bool available) { isAvailable = available; }
    bool getAvailable() { return isAvailable; }
    ostream &PrintAvailable(ostream & os);
    Relation CompareTo(Car other)
    {
        if (plateNumber < other.getPlateNumber())
            return Relation::LT;
        else if (plateNumber == other.getPlateNumber())
            return Relation::EQ;
        return Relation::GT;
    }
};

ostream &operator<<(ostream & os, Car c);

#endif /* Car_hpp */