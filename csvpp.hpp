/*
   ______________________________
 / \                             \.
|   |  WELCOME TO CSVPP!         |.
 \_ |  -----------------         |.
    |                            |.
    |  The following is an ode   |.
    |  to all the people who     |.
    |  think python is stupid    |.
    |                            |.
    |                            |.
    |  CREATED BY:               |
    |    SuperiorSeaPickle       |.
    |                            |.
    |                            |.
    |                            |.
    |                            |.
    |   _________________________|___
    |  /                            /.
    \_/____________________________/.


*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <sys/stat.h>
using namespace std;

class csv
{
private:
    bool pathExists(const string &s)
    {
        struct stat buffer;
        return (stat(s.c_str(), &buffer) == 0);
    }

public:
    string CsvPath;
    char Delimeter;
    int HeaderLines;
    int IndexColumn;
    
    csv( string path, int headerLines = 1, int indexColumn = 1, char delim = ',')  {
        CsvPath = path;
        Delimeter = delim;
        HeaderLines = headerLines;
        IndexColumn = indexColumn;

    }
    ~csv() { }
    vector<vector<string>> readCSV() {

        //argument validity checks


        //open file
        ifstream in(CsvPath);
        if (!in)
        {
            cout << "ERROR: FILE OPEN FAIL" << "\n";
        }
            
        //store each row as an index in a vector(account for HeaderLines)
        vector<vector<string>> data;
        string row;
        vector<string> rowDel;
        int coloumns = 0;
        int lastDelim;
        int rowLen = row.length();

        while (getline(in, row))
        {
        if(row.length() > 0)

            lastDelim = 0;
            rowDel.clear();
            coloumns = 0;
            for (int i = 0; i < row.length() ; i++)
            {
                if (row.at(i) == Delimeter || i == row.length() - 1)
                {
                    if (i == row.length() - 1)
                    {
                        rowDel.push_back(row.substr(lastDelim + coloumns - 1));
                        coloumns++;
                        lastDelim = i;
                    } else
                    {
                        rowDel.push_back(row.substr(lastDelim + coloumns, i - (lastDelim + coloumns)));
                        coloumns++;
                        lastDelim = i;
                    }

                }
                
            }
            
            data.push_back(rowDel);
        }
        return data;   
    }
    void writeCSV(string writePath, vector<vector<string>> data, bool isNewFile, bool isDestructive = false, char delim = ',') //figure out how to make defauilt delim csv::Delimeter
    {
        if (isNewFile)
        {
            string row;
            vector<string> newRows;
            
            if (pathExists(writePath)) //remember to check if pathExists function works
            {
                int i = 0;
                while (pathExists(writePath))
                {
                    i++;
                    writePath = writePath.substr(0, writePath.find(".csv"));
                    writePath = writePath + to_string(i);
                    writePath = writePath + ".csv";
                }
            }
            ofstream myFile(writePath);

            for (int r = 0; r < data.size(); r++)//re-delimiting vector<vector<string>> to idevisual lines
            {
                for (int c = 0; c < data[r].size(); c++)
                {
                    if (c == 0)
                    {
                        row = data[r][c] + delim;
                    }else if (c == 1)
                    {
                        row = row + data[r][c] + delim;
                    }else
                    {
                        row= row + data[r][c];
                    }
                    
                    
                }
                
                newRows.push_back(row);

            }
            for (int i = 0; i < newRows.size(); i++)
            {
                myFile << newRows[i] << endl;
            }
            
            myFile.close();
        }else //isNewFile == false
        {
            string row;
            vector<string> prevRows;
            vector<string> newRows;

            if (!isDestructive)
            {
                ifstream in(writePath);
                if (!in)
                {
                    cout << "ERROR: FILE OPEN FAIL" << "\n";
                    return;
                }
                while (getline(in, row))
                {
                    if(row.length() > 0)
                    {
                        prevRows.push_back(row);
                    }
                }
            }
            
            ofstream myFile(writePath);

            for (int r = 0; r < data.size(); r++)//re-delimiting vector<vector<string>> to idevisual lines
            {
                if (!isDestructive)
                {
                    r = r + HeaderLines;
                }
                
                for (int c = 0; c < data[r].size(); c++)
                {
                    if (c == 0)
                    {
                        row = data[r][c] + delim;
                    }else if (c == 1)
                    {
                        row = row + data[r][c] + delim;
                    }else
                    {
                        row= row + data[r][c];
                    }
                    
                }
                
                newRows.push_back(row);
            }
            for (int i = 0; i < newRows.size(); i++)
            {
                prevRows.push_back(newRows[i]);
            }
            for (int i = 0; i < prevRows.size(); i++)
            {
                myFile << prevRows[i] << endl;
            }
            
            myFile.close();
        }
    }

};
