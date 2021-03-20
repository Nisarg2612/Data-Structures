#include "Menu.hpp"

LinkedList carList = LinkedList();
ArrayList revList = ArrayList();

void Menu:: runMenu()
{
    for (;;)
    {
        printMenu();
    }
}

void Menu::printMenu()
{
    int menuchoice;
    string junk;
    Menu menu;

    cout << "\n ----------------------------------------" << endl;
    cout << "               XYZ Car Rental ";
    cout << "\n ----------------------------------------" << endl;
    cout << "\n 1. List all cars." << endl;
    cout << "\n 2. Add car to inventory." << endl;
    cout << "\n 3. Remove car from inventory." << endl;
    cout << "\n 4. List all reservations." << endl;
    cout << "\n 5. Add a reservations." << endl;
    cout << "\n 6. Cancel reservation." << endl;
    cout << "\n 7. Exit." << endl;
    cin >> menuchoice;
    switch (menuchoice)
    {
    /* constant-expression */
    case 1:
        menu.ListCars();
        break;

    case 2:
        menu.addCar();
        break;

    case 3:
        menu.removeCar();
        break;

    case 4:
        menu.ListRes();
        break;

    case 5:
        menu.addRes();
        break;

    case 6:
        menu.cancelRes();
        break;

    case 7:
        exit(0);
        break;

    default:
        break;
    }
}

void Menu::
    ListCars()
{
    cout << carList << endl;
}

void Menu::addCar()
{
    Car c;
    string inPlateNumber;
    string inMake;
    string inModel;
    vehicleType inVehicleType;
    double inPricePerDay;
    bool isAvailable = true;

    cout << "Please enter the following information "
         << "add" << endl;
    cout << "PlateNumber: ";
    cin >> inPlateNumber;
    c.getPlateNumber() = inPlateNumber;
    cout << "Make: ";
    cin >> inMake;
    cout << "Model: ";
    cin >> inModel;
    cout << "VehicleType(0 = sedan, 1 = suv, 2 = exotic): ";
    cin >> inVehicleType;

    while (inVehicleType < vehicleType::sedan || inVehicleType > vehicleType::exotic)
    {
        cout << "Invalid input, Prompt again" << endl;
        cin >> inVehicleType;
        break;
    }

    cout << "Price per day to rent: $ ";
    cin >> inPricePerDay;

    c = Car(inPlateNumber, inMake, inModel, inVehicleType, inPricePerDay, isAvailable);
    carList.putCar(c);

}

void Menu::removeCar()
{
    Car c;
    string inPlateNumber;
    cout << "Please enter the car plate number to remove: ";
    cin >> inPlateNumber;
    carList.deleteCar(Car(inPlateNumber, "", "", sedan, 0, true));
}

void Menu::ListRes()
{
    cout << revList << endl;
}

void Menu::addRes()
{
    string name;
    int choice;
    int cancel;
    string plateNumber;
    Car c;

    cout << "Please enter your name: ";
    cin >> name;
    carList.printAvailCar(cout);
    cancel = carList.getLength() + 1;
    cout << cancel << "Cancel" << endl;
    cout << "Please enter the plate number of the car for reservations: ";
    cin >> choice;
    if (choice == cancel)
        return;
    else
    {
        c = carList.getCarAtIndex(choice);
        carList.deleteCar(Car(c.getPlateNumber(), "", "", sedan, 0, true));
        carList.putCar(Car(c.getPlateNumber(), c.getMake(), c.getModel(), c.getVehicleType(), c.getPricePerDay(), false));
        plateNumber = c.getPlateNumber();
        Reservation r(name, plateNumber);
        revList.rPutCar(r);
    }
}

void Menu::cancelRes()
{
    string name;
    Reservation r;
    Car c;
    bool temp = false;

    cout << "Please enter the same name as on reservation: ";
    cin >> name;
    r = Reservation(name, "");
    revList.rDeleteCar(revList.rGetCar(r, temp));
    c.setAvailable(true);
}