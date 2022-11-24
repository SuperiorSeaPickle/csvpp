#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class csv
{
private:
    string csvPath;


public:
    
    csv(string path) {
        csvPath = path;
    }
    ~csv();
    //headerlines = what lines of csv file are headers. dataType = for each colounm what the data type is(must be how it is writen syntacticly in c++)
    void readCSV(string delimeter, int headerLines, vector<string> dateType) {
        //open file
        ifstream in(csvPath);
        //store each row as an index in a vector(account for headerLines)

        //seperate values in each index based on delimeter before sorting in coresponding colounm vector(remember that this for summery format not indevisual. Maybe you could give a choice to the user)
    }

};
