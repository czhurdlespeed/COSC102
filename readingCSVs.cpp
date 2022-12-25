#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string> //needed for get line
using namespace std;


// fin >> fname >> last >> AGE >> ageInt; -Will not work because we do not know how many words the first name will be
// We will fix this by using string stream and get line



int main() {
    ifstream fin("mycsvfile.txt");

    if(!fin.is_open()) {
        cerr <<"File failed to open." << endl;
        return 1;
    }
// getline (stream, string, char)
// the char is optional but it tells getline where to stop
    string line, firstName, lastName, tempString, tempAge;
    int age;
// IMPORTANT : all of the vector stuff here is simply an extra way to do the same thing. 
//You can ignore all the vector stuff at first
    vector <vector <string> > dataTable;
    vector <string> person;

    while(getline(fin, line)) {
        istringstream ss(line);
        getline(ss, firstName, ',');
        person.push_back(firstName);

        getline (ss, lastName, ',');
        person.push_back(lastName);

        getline (ss, tempString, ',');
        getline (ss, tempAge, ',');
        person.push_back(tempAge);
        age = stoi(tempAge);
        cout << firstName << " " << lastName  << " " << age << endl;

        dataTable.push_back(person);


    }
    for (int i = 0; i <dataTable.size(); i++) {
        for (int j = 0; j < dataTable[0].size(); j++) {

        }
    }
    fin.close();

}