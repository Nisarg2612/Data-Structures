#ifndef CarLinkedList_hpp
#define CarLinkedList_hpp

#include <iostream>
#include <string>
#include "Car.hpp"
using namespace std;

struct Node{
    Car data;
    Node* next;
};

class LinkedList{
private:
    int length;
    Node* currentPos;
    Node* head;

public:
    LinkedList(): currentPos{0}, length{0}{}
    ~LinkedList();
    void makeEmpty();
    void putCar(Car car);
    Car& getCar(Car car, bool& found);
    void deleteCar(Car car);
    void resetList();
    Car getNextCar();
    Car& getCarAtIndex(int index);
    int getLength();
    void printAvailCar( ostream& os );

};

ostream& operator<<(ostream& os, LinkedList& l);

#endif /* CarLinkedList_hpp */