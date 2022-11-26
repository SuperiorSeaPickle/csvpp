#include <iostream>
#include <vector>
using namespace std;

class person
{
private:
    /* data */
public:

    int index;
    double hight;
    double weight;

    person(int i, double h, double w)
    {
        index = i;
        hight = h;
        weight = w;
    }
    ~person() { }
};