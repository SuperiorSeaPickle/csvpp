#include <iostream>
#include <vector>
#include <map>
#include "csvpp.hpp"
#include "person.hpp"
using namespace std;

int main()
{
    csv hightWeight("hw_25000.csv", ',', 1, 1);
    vector<vector<string>> csv2dVec = hightWeight.readCSV();
    
    return 0;
}