#include "Car.hpp"

Car::Car(string plateNumber, string make, string model, vehicleType vType, double ppd, 
         bool isAvail):

        plateNumber(plateNumber),
        make{make}, 
        model{model},
        vType(vType),
        PricePerDay(ppd),                             
        isAvailable(isAvailable){
}

ostream &operator<<(ostream &os, Car c)
{
    vehicleType vt = c.getVehicleType();
    os << c.getMake() << " " << c.getModel() << " (" << typeNames[vt] << ") " 
            << "$" << c.getPricePerDay()<< "/day" << endl;
    return os;
}

ostream & Car::PrintAvailable(ostream & os)
{
    vehicleType vt = getVehicleType();
    os << "[" << getPlateNumber() << "] " << getMake() << " "
        << getModel() << " (" << typeNames[vt] << ") " << endl;

    return os;
}