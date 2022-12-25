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

int main() {
    ifstream fin;
    string last, first;
    int h,m,s;
    vector <string> lastNames;
    vector <string> firstNames;

    fin.open("racetimesHMS.txt");
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