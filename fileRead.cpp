/*
Reading in Files/Writing to Files - Using File Streams
1. Include <fstream> header file
2. Delcare a file variable (ifstream for reading - stands for input file stream) (ofstream for writing - output  file stream)
    and name it (typically fin, fout)
3. 3a. Open the file connecting the variable to the actual file 3b. check for failure to open.
4. Do the work on the intended file (either read from the file or write to the file) using <<,>>
*/

#include <iostream>
#include <fstream>
using namespace std;


int main() {
    ifstream  fin;
    int a, b, c;
    fin.open("FR1.txt"); // this is often forgotten; creates stream of information between our program and the file/path info
    if (!fin.is_open()) { // or use fin.fail() could also error check.
        cout << "Could not open FR1.txt" << endl;
        return 1; // shows that an error has occurred
    }
    //fin >> a >> b >> c; // nothing to read after a,b,c
    // getline(STREAM, STRING);
    string line, line2;
    getline(fin,line); // this will place 3 10 15 in a string (that string is line)
    cout << line << endl;
    getline(fin,line2);
    cout << line2<< endl;
    
    fin.close(); // close the file since nothing else is left to read
    
    cout << "Verifying the Integers read in:" <<"\n"<< line << "\n"<<line2 <<endl;
    //cout << a << " "<< b<< " " << c<< endl;
}