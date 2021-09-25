#ifndef DRIVER_H
#define DRIVER_H
#include <bits/stdc++.h>
#include "ParkingLot.h"
using namespace std;

class Driver{
    ifstream input;
    string command;

    //size of reg_no of the car
    int reg_no_size =13;
    ParkingLot parking;

    //list of possible commands to parse input
    vector<string>commands = {
        "Park ",
        "Leave ",
        "Create_parking_lot ", 
        "Slot_numbers_for_driver_of_age ",
        "Slot_number_for_car_with_number ",
        "Vehicle_registration_number_for_driver_of_age "

    };

    public:
    Driver(string);
   
};
 
#endif