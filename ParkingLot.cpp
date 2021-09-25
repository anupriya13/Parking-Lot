#include <bits/stdc++.h>
#include "ParkingLot.h"

using namespace std;

ParkingLot::ParkingLot(int n)
   {
       size = n;
       empty_slots = n;
       parking_slots = vector<Slot>(n,{"",-1,false});

       //intially all slots are free therefore added in priority_queue
       for(int i=0; i<size; i++)
            free_slots.push(i);

       output.open("output.txt");
       output<<"Created parking of "<<n<<" slots"<<endl;
   }

bool ParkingLot::park(string reg_no, int age)
   {
       //checking if parking is full
       if(empty_slots == 0)
       {
           output<<"Parking is full"<<endl;
           return false;
       }

        // getting nearest free slot and removing it from priority queue
        int i = free_slots.top();
        free_slots.pop();

        // i is the nearest free slot to entry
        //parking the car in ith(nearest free slot) parking slot
        parking_slots[i].is_occupied = true;
        parking_slots[i].reg_no = reg_no;
        parking_slots[i].age = age;

        //upadating slot number for given reg_no
        reg_no_slot[reg_no] = i;

        //adding ith slot to set of slot with given age
        age_slots[age].insert(i);

        //adding given reg_number to set of reg_nos with given age
        age_reg_nos[age].insert(reg_no);

        output<<"Car with vehicle registration number \""<<reg_no<<"\" has been parked at slot number "<<i+1<<endl;

        empty_slots--;
        return true;
   }

   bool ParkingLot::vaccate(int slot_no)
   {
       //checking if parking is empty or that slot is empty
       if(empty_slots== size || parking_slots[slot_no-1].is_occupied == false)
       {
            output<<"Slot already vaccant"<<endl;
            return false;
       }
        
        empty_slots++;

        //adding given slot to free slots
        free_slots.push(slot_no-1);

        output<<"Slot number "<<slot_no<<" vacated, the car with vehicle registration number \""
        <<parking_slots[slot_no-1].reg_no<<"\" left the space, the driver of the car was of age "<<parking_slots[slot_no-1].age<<endl;

        //removing car for the slot
        parking_slots[slot_no-1].is_occupied = false;

        //removing the reg_no of car
        reg_no_slot.erase(parking_slots[slot_no-1].reg_no);

        //removing the slot_no form set of slot for age of driver of car parked in that slot number 
        age_slots[parking_slots[slot_no-1].age].erase(slot_no-1);

        //removing the reg_no form set of reg for age of driver of car parked in that slot number
        age_reg_nos[parking_slots[slot_no-1].age].erase(parking_slots[slot_no-1].reg_no);
        return true;
   }

void ParkingLot::get_slot_of_car(string reg_no)
   {
       // check if car is parked in parking lot or not
       if(reg_no_slot.find(reg_no) != reg_no_slot.end())
            output<<reg_no_slot[reg_no]+1<<endl;
        else
            output<<"Car not found"<<endl;

   }

void ParkingLot::get_reg_no(int age)
   {
       vector<string> reg_nos;

       //geting reg_no of all the cars of certain age
       for(auto i: age_reg_nos[age])
            reg_nos.push_back(i);

        //printing result to output file
        for(int i=0; i<reg_nos.size(); i++){
            output<<reg_nos[i];
            if(i != reg_nos.size()-1)
                output<<", ";
        }
        output<<endl;
        
   }

   void ParkingLot::get_slots(int age)
   {
       vector<int> slot_nos;

       //geting slot_no of all the cars of certain age
       for(auto i: age_slots[age])
            slot_nos.push_back(i);
        
        //printing result to output file
        for(int i=0; i<slot_nos.size(); i++){
            output<<slot_nos[i]+1;
            if(i != slot_nos.size()-1)
                output<<",";
        }
        output<<endl;
   }