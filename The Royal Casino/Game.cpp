#include "SlotMachine.hpp"
#include <iomanip>

using namespace std;

void printMachine(int total, int cost, SlotMachine* S_Machine){
    cout <<"---------------------" << endl;
    cout <<"| SLOT MACHINE GAME |" << endl;
    cout <<"---------------------" << endl;
    cout << "|  " << S_Machine -> getR1prev();
    cout << "   " << S_Machine -> getR2prev();
    cout << "   " << S_Machine -> getR3prev() << "  |" << endl;
    cout << "|> " << S_Machine->getR1();
    cout << "   " << S_Machine->getR2();
    cout << "   " << S_Machine->getR3() << " <|" << endl;
    cout << "|  " << S_Machine->getR1next();
    cout << "   " << S_Machine->getR2next();
    cout << "   " << S_Machine->getR3next() << "  |" << endl;
    cout << "----------------" << endl;
    cout << "| SPIN COST $" << cost << " |" << endl;
    cout << "| BALANCE $" << setw(4) << left << total << "|" << endl;
    cout << "----------------" << endl;
}

int main()
{
    // user start game with balance $100
    int total = 100;
    
    const int cost = 1; // Each spin cost $1
    // Create a slot machine
    SlotMachine *S_Machine = new SlotMachine();
    // Spin slot machine at start
    S_Machine->Spin();
    // Print welcome message
    cout << " WELCOME TO THE ROYAL CASINO " << endl;
    // Print slot machine
    printMachine(total, cost, S_Machine);
    // Ask user for option to play until exit
    char option;
    while (option != 'Q' && option != 'q')
    {
        cout << " SELECT OPTION: " << endl;
        cout << "  P. PLAY" << endl;
        cout << "  Q. QUIT" << endl;
        cin >> option;
        if (option == 'P' | option == 'p')
        {
            // Check if user have enough balance
            if (total > cost)
            {
                // Let user play the game
                S_Machine->Spin();
                // Get payout
                int payout = S_Machine->payout();
                // Check if it is jacpot
                if (payout == 500)
                {
                    // Print jacpot message
                    cout << " JACKPOT! " << endl;
                }
                // Remove cost from balance
                total = total - cost;
                // Add winning prize to total balance
                total = total + payout;
                // Print  slot machine
                printMachine(total, cost, S_Machine);
                // Print winning amount
                cout << " YOU WON $" << payout << endl;
            }
            else
            {
                // User out of money
                cout << " YOU DO NOT HAVE ENOUGH MONEY!" << endl;
            }
        
        }
    
    }
    return 0;
}