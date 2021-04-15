#include "SlotMachine.hpp"
#include <iomanip>

SlotMachine::SlotMachine()
{
    // Initialize all reels
    left_r = new Reel();
    middle_r = new Reel();
    right_r = new Reel();
    // Add data to left real
    left_r->insert('A');
    left_r->insert('A');
    left_r->insert('A');
    left_r->insert('A');
    left_r->insert('B');
    left_r->insert('B');
    left_r->insert('B');
    left_r->insert('C');
    left_r->insert('C');
    left_r->insert('7');
    // Add data to middle reel
    middle_r->insert('B');
    middle_r->insert('B');
    middle_r->insert('B');
    middle_r->insert('A');
    middle_r->insert('A');
    middle_r->insert('A');
    middle_r->insert('A');
    middle_r->insert('7');
    middle_r->insert('C');
    middle_r->insert('C');
    // Add data to right reel
    right_r->insert('C');
    right_r->insert('C');
    right_r->insert('7');
    right_r->insert('B');
    right_r->insert('B');
    right_r->insert('B');
    right_r->insert('A');
    right_r->insert('A');
    right_r->insert('A');
    right_r->insert('A');
}

SlotMachine::~SlotMachine()
{
    // Delete value of each reel after spin
    delete left_r;
    delete middle_r;
    delete right_r;
}

void SlotMachine::Spin()
{
    int roll = rand() % 100; // Get random number from 0 to 99
    // Spin left reel for random number times
    for (int i = 0; i < roll; i++)
    {
        left_r->head = left_r->head->next;
    }
    // Spin middle reel 
    roll = rand() % 100;
    for (int i = 0; i < roll; i++)
    {
        middle_r->head = middle_r->head->next;
    }
    // Spin right reel
    roll = rand() % 100;
    for (int i = 0; i < roll; i++)
    {
        right_r->head = right_r->head->next;
    }
}

int SlotMachine::payout()
{
    // Get data from each reel
    char c1 = left_r->head->data;
    char c2 = middle_r->head->data;
    char c3 = right_r->head->data;
    // Check for combination
    if (c1 == c2 && c2 == c3)
    {
        if (c1 == 'A')
        {
            return 6;
        }
        else if (c2 == 'B')
        {
            return 15;
        }
        else if (c3 == 'C')
        {
            return 50;
        }
        else
        {
            return 500;
        }
    }
    else
    {
        return 0;
    }
}

char SlotMachine::getR1prev()
{
    return left_r->head->prev->data;
}

char SlotMachine::getR1()
{
    return left_r->head->data;
}
char SlotMachine::getR1next()
{
    return left_r->head->next->data;
}

char SlotMachine::getR2prev()
{
    return middle_r->head->prev->data;
}

char SlotMachine::getR2()
{
    return middle_r->head->data;
}
char SlotMachine::getR2next()
{
    return middle_r->head->next->data;
}

char SlotMachine::getR3prev()
{
    return right_r->head->prev->data;
}

char SlotMachine::getR3()
{
    return right_r->head->data;
}
char SlotMachine::getR3next()
{
    return right_r->head->next->data;
}