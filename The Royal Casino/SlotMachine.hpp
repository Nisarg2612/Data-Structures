#ifndef SlotMachine_hpp
#define SlotMachine_hpp

#include "Reel.hpp"
#include <iostream>

class SlotMachine
{
private:
    Reel *left_r;   // Left reel
    Reel *middle_r; // Middle reel
    Reel *right_r;  // Right reel
public:
    SlotMachine();    // Slot machine constructor
    void Spin();      // Spin the reels and get head of each reel to random position
    int payout();     // Return amount of payout for given combination
    char getR1prev(); // Return previous element from left reel head
    char getR1();     // Return head of left reel
    char getR1next(); // Return next element from left reel head
    char getR2prev(); // Return previous element from middle reel head
    char getR2();     // Return head of middle reel
    char getR2next(); // Return next element from middle reel head
    char getR3prev(); // Return previous element from right reel head
    char getR3();     // Return head of right reel
    char getR3next(); // Return next element from right reel head
    ~SlotMachine();   // Slot machine destructor
};

#endif /* SlotMachine_hpp */