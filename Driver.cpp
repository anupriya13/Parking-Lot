#include <bits/stdc++.h>
#include "Driver.h"

using namespace std;

Driver::Driver(string inputfile)
    {
        input.open(inputfile);

        //reading file line by line in input file
        while (getline(input, command))
        {
            if(command.substr(0, commands[0].size()) == commands[0]) 
            {
                string age = "";
                for(int i= command.size()-1; command[i] != ' '; i--)
                    age+=command[i];
                reverse(age.begin(), age.end());
                string reg_no = command.substr(commands[0].size(), reg_no_size);
                parking.park(reg_no, stoi(age));
                
            }
            else if(command.substr(0, commands[1].size()) == commands[1])
            {
               
                string slot_no = command.substr(commands[1].size(), command.size() - commands[1].size());
                parking.vaccate(stoi(slot_no));
            }
            else if(command.substr(0, commands[2].size()) == commands[2])
            {
                string size = command.substr(commands[2].size(), command.size()-commands[2].size());
                parking = ParkingLot(stoi(size));
            }
            else if(command.substr(0, commands[3].size()) == commands[3])
            {
                string age = command.substr(commands[3].size(), command.size() - commands[3].size());
                parking.get_slots(stoi(age));
            }
            else if(command.substr(0, commands[4].size()) == commands[4]){
                string reg_no = command.substr(commands[4].size(), command.size() - commands[4].size());
                parking.get_slot_of_car(reg_no);
            }
            else if(command.substr(0, commands[5].size()) == commands[5])
            {
                string age = command.substr(commands[5].size(), command.size() - commands[5].size());
                parking.get_reg_no(stoi(age));
            }
            
        }
    }