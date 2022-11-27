# csvpp
# WELCOME TO CSVPP

*CSVPP* is a open source header file for CSV manipulation in c++. 


# FUNCTIONALITY

CSVPP has some important functionality, as well as many more to come. Before you can do anything however, you must first instantiate the `csv` class to do anything useful. The `csv` class constructor layout:
	**REQUIRED ARGUMENTS:**
	

    string path
This is the path of the csv file you are creating the object for
**DEFAULT ARGUMENTS:**

    int  headerLines = 1, int  indexColumn = 1, char  delim = ','
`headerLines` - up to what lines in csv files are headers (not raw data)
`indexColumn` - the column used to keep track of data (ex.  User ID)
`delim` - The character that will seperate values (comma is slandered)

**EXAMPLE:**
Valid implementation of this could look like the following:

    csv hightWeight("hw_25000.csv");

## READ CSV FILES

To read a CSV file with *CSVPP*, you must create a `vector<vector<string>>`, before assigning it the value of your csv object's `readCSV()`function. It will use the properties attached to your csv object to return a `vector<vector<string>>` version of the CSV file. The return value has the layout rows< columns >>

 **EXAMPLE:**
 

    vector<vector<string>> csv2dVec = hightWeight.readCSV();
   If my `csv hightWeight` looks like:
   
|Index|Height|Weight|
|--|--|--|
|1|65.78331|112.9925|
|2|71.51521|136.4873|
|3|69.39874|153.0269|

Than `hightWeight.readCSV()` will look like:

    [0]
    ==>[0] - Index
    ==>[1] - Height
    ==>[2] - Weight
    [1]
    ==>[0] - 1
    ==>[1] - 65.78331
    ==>[2] - 112.9925
    [2]
    ==>[0] - 2
    ==>[1] - 71.51521
    ==>[2] - 136.4873
    [3]
    ==>[0] - 3
    ==>[1] - 69.39874
    ==>[2] - 153.0269



## WRITE CSV FILES

The `writeCSV()` function has 5 arguments in total. 
	**REQUIRED ARGUMENTS:**
	

    string  writePath, vector<vector<string>> data, bool  isNewFile
`writePath` - The new path you would like to write your CSV file to
`data` - The data you write to the file
`isNewFile` - If true, there will always be a new file created even if the directory already exists. False, it will write to an existing CSV file.

**DEFAULT ARGUMENTS:**

    bool  isDestructive = false, char  delim = ','
`isDestructive` - Can only be true if `isNewFile` is false. If that is such, it will replace all the data in the existing CSV file. If false, the new data will be added as new lines. 
`delim` - Delimiter (comma is standard)


# AUTHORIZATION

 1. The following source code must be credited to its owner
 2. If you would like to change source code, you must fork the repository
 3. You may not sell the contents of this code for any reason
 4. The original creator is not responsible for any damages caused by software that uses this source code. 