/*
Reading in an unkown amount of lines with a know column organization
1. Include <fstream> header file
2. Delcare a file variable (ifstream for reading - stands for input file stream) (ofstream for writing - output  file stream)
    and name it (typically fin, fout)
3. 3a. Open the file connecting the variable to the actual file 3b. check for failure to open.
4. Do the work on the intended file (either read from the file or write to the file) using <<,>>
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



int main() {
    ifstream  fin;
    int a, b, c;
    vector < vector <int> > linesVector; // vector that holds vector of integers (triplet vector)
    fin.open("FR2.txt");  // can put path in here; doesn't have to be just file name
    if (!fin.is_open()) { 
        cout << "Could not open FR2.txt" << endl;
        return 1; 
    }
    
    // Read in multiple lines of data
    while (fin >> a >> b >>c) {
        cout << "Verifying - you read: ";
        cout << a << " "<< b << " "<< c<< endl;
        vector  <int>  triplet;
        triplet.push_back(a);
        triplet.push_back(b);
        triplet.push_back(c);
        linesVector.push_back(triplet);
    }
    for (int i =0; i<linesVector.size(); i++) {
        for (int j =0; j<3; j++) {
            cout << linesVector[i][j] << " ";
        }
        cout << endl;
    }
    fin.close();
}