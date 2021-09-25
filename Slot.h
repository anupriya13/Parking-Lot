#ifndef SLOT_H
#define SLOT_H
#include <bits/stdc++.h>
using namespace std;
//Class representing single slot in parking
class Slot{
    public:
    string reg_no;
    int age;
    bool is_occupied;
    Slot(string reg_no, int age,bool is_occupied)
        :
        reg_no(reg_no),
        age(age),
        is_occupied(is_occupied){}


};

#endif