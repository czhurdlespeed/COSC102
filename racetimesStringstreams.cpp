/* String Streams Notes
The string stram class is used for insertion and extraction of 
data to/from strings. It acts as a stream for the string object

Similar to cin/cout, fin/fout
The stream is just from a different source
Source for cin/cout - console
Source for fin/fout - file
Source for sin/sout - string 

getline() on HMS text file with a string line

string hr = "3";

Program will take 3 arguments on the command line:
1. Program name (the executable)
2. Input file (racetimeHMS.txt)
3. Output file (a new file, but we give it a name here)
*/ 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

/* Returns the marathon time as a string in HH:MM:SS format */
string formatTime(int h, int m, int s) {
    ostringstream sout;
    sout <<setfill('0')<< setw(2) << h << ":"<< setw(2) <<m <<":"<< setw(2) <<s; // setw(2) must be repeated but setfill('0') only needs to be written once
    // creating the string format using sout
    return sout.str(); // don't forget this part to turn the stream into a string
}

string calcPace(int h, int m, int s) {
    ostringstream sout;
    int totalSeconds = (h*60*60)+(m*60) + (s);
    double paceInSeconds = (totalSeconds/26.2);
    int pMin = (int) (paceInSeconds/60); // truncate (drop) the decimals
    int pSec = (((int) (paceInSeconds + 0.5))%60);
    sout << setfill('0') << setw(2) << pMin << ":" << setw(2) << pSec;
    return sout.str();
}

int main(int argc , char **argv) {
    ifstream fin;
    ofstream fout;
    string fname, lname, time, pace, inputFilename, outputFilename;
    int hrs, mins, secs;

    if (argc != 3) { // if number of arguemnts does not equal 3
        cerr << "usage: ./racetimesStringstreams inputFilename.txt outputFilename.txt \n";   // console error; like cout but for errors
        return 1;
    }

    inputFilename = argv[1];
    outputFilename = argv[2];

    // argv[0] = ./racetimesStringstreams   (its equal to the executable)
    /* Connecting the file input stream with the file and making sure it opens correctly */

    fin.open(inputFilename);
    if (!fin.is_open()) {
        cerr << "Could not open file. Check permissions or filename.\n";
        return 1;
    }
    fout.open(outputFilename);
    /* Create a output file to place the newly formatted data */
    while (fin>> fname >> lname>> hrs >> mins>> secs) {
        // write FNAME LNAME
        // newline, 2 space, formatted time
        fout << fname << " " << lname<< endl;
        time = formatTime(hrs, mins,secs);
        fout << "  "<< "Marathon Time: "<< time<<endl;
        pace = calcPace(hrs,mins,secs);
        fout << "  "<< "Pace: " << pace << endl;


    }
    fin.close();
    fout.close();
    return 0;



}