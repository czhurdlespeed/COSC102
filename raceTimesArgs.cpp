/* Using Argc and Argv      - adds data to file via command line
Use this to force the user to give us specific information on the command line when they run the program
This example will force the user to give us the input file name.
This will looke like: ./raceTimesArgs fileName
when they run the program
1. We have always main as main() - change that to       argc = argument count    argv = argument value
    int main(int argc, char **argv) OR
    int main(int argc, char *argv[])
    NOTE: argv is an array of c-style strings. We will have to translate that to c++ strings
    argc = argument count. in this program, it should be 2 (the executable counts)
    argv = argument values - defined from 0 to argc-1  e.g. argv[0] = raceTimesArgs  argv[1] = filename
2. Check to see if argc is equal to what the usage calls for (we get to decide the usage)
3. Change any argvs that we want to use to c++ strings if needed
______

/* 1. Include <fstream> header file
2. Delcare a file variable (ifstream for reading - stands for input file stream) (ofstream for writing - output  file stream)
    and name it (typically fin, fout)
3. 3a. Open the file connecting the variable to the actual file 3b. check for failure to open.
4. Do the work on the intended file (either read from the file or write to the file) using <<,>>
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char **argv) {
    ifstream fin;
    string last, first, filename;
    int h,m,s;
    vector <string> lastNames;
    vector <string> firstNames;
    if (argc !=2) {
        cout << "usage: ./raceTimesArgs filename" << endl;
        return 1;
    }
    
    //Take argv[1] and set it to filename
    filename = argv[1];

    fin.open(filename);
    if (fin.fail()) {
        cout << "racetimeHMS.txt failed to open" <<endl;
        return 1;
    }

    while (fin >> first >> last >> h >> m>> s) {
        // Anything we do in this while loop will occur for every single line
        cout << "You read: " << last << ", "<<first<<endl;
        firstNames.push_back(first);
        lastNames.push_back(last);
    }

    cout << "Person #3 is " << firstNames[2]<< " " << lastNames[2] << endl;

}