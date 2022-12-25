/* Program Name: boiling.cpp
Student Name: Jon Calvin Wetzel
Net ID: jwetzel2
Student ID: 000625680
Program Description: boiling.cpp (Lab 6) is a boiling point calculator for various locations (changes in altitude).
    The program takes a csv file and lists the available locations. The user selects a location and the respective boiling
    point is outputted. 
*/

#include <iostream> //imported required libraries 
#include <sstream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main(int argc, char **argv) { //entering main() and using argc and argv 
    string line, filename, city, state, temp_elevations; // delcaring variable data types
    int number;
    double pressure, boilingpt;
    vector <string> cityNames;
    vector <int> elevations;
    vector<vector<string>> dataTable;
    vector <string> location;
    if (argc !=2) { // if number of arguments is not 2 then output error message and stop program
        cerr << "usage: ./boiling my-input-file.csv"<<endl;
        return 1;
    }

    filename = argv[1]; // file name is the value of the second argument

    ifstream fin(filename); // declaring filestream

    if (!fin.is_open()) { // if file fails to open, then throw an error message and stop program
        cerr << "File failed to open."<< endl;
        return 1;
    }

    getline(fin,line); // used to bypass the first line in each file which are categorical designators
    while (getline(fin,line)) { // while a line in the csv file still exists
        istringstream ss(line); // delcaring stringstream
        getline(ss,city,','); // assigning first value of line to city
        location.push_back(city); // pushing value back to location and cityNames vectors
        cityNames.push_back(city);
        
        getline(ss,state,','); //assigning second value of line to state
        location.push_back(state); //pushing back state to location vector

        getline(ss,temp_elevations,','); //assinging third value of line to temp_elevations because I declared it as a string
        location.push_back(temp_elevations); // pushing back to location vector
        elevations.push_back(stoi(temp_elevations)); // converting temp_elevations to an integer using stoi and pushing it to elevations vector
        dataTable.push_back(location); // pushing back location vector to dataTable 2D vector
        location.clear(); // clearing the location vector so that the next line of information will be stored in location properly
        
    }
  
    fin.close(); // closing the reading of the file
    cout<< "Boiling Point at Altitude Calculator"<< endl; // outputting title of list of locations
    for (int i=0; i <dataTable.size(); i++) { // embedded for loop in a for loop. Used to index within a 2D vector. Indexing within dataTable vector
         for (int j = 0; j <dataTable[i].size(); j++){
            cout << to_string(i+1) << ". "<<dataTable[i][j]<< endl; // outputting the various locaitons in the dataTable. Could do the same thing with cityNames vector but I chose this path
            break; // break for loop once the locaiton has been outputted (don't want the rest of the info in the dataTable row)
        }    
    }
    cout<< "Enter a city number: "; // asking user for city number
    cin >> number;

    pressure = 29.921 * pow((1- 0.0000068753*elevations[number-1]),5.2559); // pressure in inHg
    boilingpt = 49.161*log(pressure)+44.932; // degrees farenheit
    cout <<"The boiling point at "<<dataTable[number-1][0]<< " is "<< setprecision(3)<<fixed<< boilingpt << " degrees Farenheit."<<endl; // final output with boiling point for the selected location
    
}