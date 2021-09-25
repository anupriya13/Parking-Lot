#include<bits/stdc++.h>
#include "Driver.h"

using namespace std;

int main()
{
    Driver d("input.txt");
    // for input -> input.txt
    // for output -> output.txt

    // output.txt -> stdout
    ifstream output;
    output.open("output.txt");
    string command;
    while (getline(output, command)){
      cout<<command<<endl;
    }

    return 0;
}