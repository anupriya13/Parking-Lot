#ifndef PARKINGLOT_H
#define PARKINGLOT_H
#include <bits/stdc++.h>
#include "Slot.h"
using namespace std;

class ParkingLot{
   int size;

   //array of parking slots
   vector<Slot>parking_slots;

   //number of vaccant slots in parking
   int empty_slots;

   //list of free slots stored in min heap(priority queue) to get nearest free slot in log n time
   priority_queue<int,vector<int>, greater<int>>free_slots;

   // map maintaining all slots for particuar age
   unordered_map<int,set<int>>age_slots;

   // map maintaining all registration numbers for particuar age
   map<int,set<string>>age_reg_nos;
   
   //map storing slot number for specific car
   map<string, int>reg_no_slot;

   ofstream output;

   
   public:
   ParkingLot() = default;

   //intializing parkinglot of given size;
   ParkingLot(int);
   
   bool park(string, int);
  
   bool vaccate(int);

   void get_slot_of_car(string);

   void get_reg_no(int);
   
   void get_slots(int);

};

#endif