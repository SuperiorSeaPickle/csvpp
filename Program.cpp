#include <iostream>
#include <vector>
#include <map>
#include "csvpp.hpp"
#include "person.hpp"
using namespace std;

int main()
{
    csv hightWeight("hw_25000.csv");
    vector<vector<string>> csv2dVec = hightWeight.readCSV();
    hightWeight.writeCSV("newHW.csv", csv2dVec, false);
    return 0;
}