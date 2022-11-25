#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class csv
{
private:
    string csvPath;


public:
    
    csv(string path) {
        csvPath = path;
    }
    ~csv() { }
    //headerlines = what lines of csv file are headers. dataType = for each colounm what the data type is(must be how it is writen syntacticly in c++)
    static vector<int> DEFAULT_VECTOR;
    void readCSV(string delimeter, int primaryHeader, vector<string> dateType, vector<int> secondaryHeaders = DEFAULT_VECTOR) {
        //open file
        ifstream in(csvPath);
        if (!in)
        {
            cout << "ERROR: FILE OPEN FAIL" << "\n";
            return;
        }
        
        //store each row as an index in a vector(account for primaryHeader)
        vector<string> data;
        string row;

        while (getline(in, row))
        {
        if(row.size() > 0)
            data.push_back(row);
        }

        //seperate header lines
        vector<string> headers;
        for (int i = 0; i < primaryHeader; i++)
        {
            headers.push_back(data[i]);
            
        }
        data.erase(data.begin(), data.begin() + primaryHeader);
        //seperate values in each index based on delimeter before sorting in coresponding colounm vector(remember that this for summery format not indevisual. Maybe you could give a choice to the user)
        for (int i = 0; i < data.size(); i++)
        {
            /* code */
        }
        
    }

};
