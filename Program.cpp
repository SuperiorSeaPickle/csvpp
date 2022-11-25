#include <iostream>
#include <vector>
#include "csvpp.hpp"
using namespace std;

int main()
{
    csv treeRingData("BEN ALEX Tree Ring Data - ALL - Tree Ring Data ALL 2022.csv");
    vector<string> dataTypes(30, "double");
    treeRingData.readCSV(",", 5, dataTypes);
    return 0;
}