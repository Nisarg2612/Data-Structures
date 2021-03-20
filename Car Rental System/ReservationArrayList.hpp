#ifndef ReservationArrayList_hpp
#define ReservationArrayList_hpp

#define MAX_ELEMS 100

#include "Reservation.hpp"
#include "Car.hpp"

class ArrayList
{
private:
    int currentPos;
    int length;
    Reservation data[MAX_ELEMS];

public:
    ArrayList() : currentPos{0}, length{0} {}
    void rMakeEmpty();
    void rPutCar(Reservation res);
    Reservation rGetCar(Reservation res, bool &found);
    void rDeleteCar(Reservation res);
    void rResetList();
    Reservation rGetNextCar();
    int rGetLength();
};

ostream &operator<<(ostream &os, ArrayList &a);

#endif /* ReservationArrayList_hpp */