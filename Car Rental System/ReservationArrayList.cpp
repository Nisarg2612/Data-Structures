#include "ReservationArrayList.hpp"

ostream& operator<<(ostream& os, ArrayList& a){
    a.rResetList();
    os << "Reservation List: \n";
    for(int i = 0; i < a.rGetLength(); ++i){
        int index = i;
        os << index + 1 << ". " << a.rGetNextCar();
    }
    os << endl;
    return os;
}

void ArrayList::rMakeEmpty(){
    length = 0;
}
void ArrayList::rPutCar(Reservation res){
    data[length++] = res;
}

Reservation ArrayList::rGetCar(Reservation res, bool& found){
    found = false;
    for(int i = 0; i < length; ++i){
        if (data[i].CompareTo(res) == Relation::EQ) {
            res = data[i];
            found = true;
            break;
        }
    }
    return res;
}

void ArrayList::rDeleteCar(Reservation res){
    for(int i = 0; i < length; ++i){
        if (data[i].CompareTo(res) == Relation::EQ)
            data[i] = data[--length];
    }
}

void ArrayList::rResetList(){
    currentPos = 0;
}

Reservation ArrayList::rGetNextCar(){
    if(currentPos < length)
        return data[currentPos++];

    throw "Out of Range";
}

int ArrayList::rGetLength(){
    return length;
}