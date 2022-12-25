/* Jon Calvin Wetzel
CS102
NetID: jwetzel2
StudentID: 000625680
Lab 2 Penname
09/07/2022 */

#include <iostream> // including iostream 
#include <vector> // including vector incase needed
using namespace std;

int main() {
    string firstname, lastname,streetType,cityBorn,streetName,newStreetName; //declaring string variables
    int streetNum, newAge,age,newStreetNum; // declaring integer variables

    cout<<"Enter your first and middle names: "; // asking for first and middle names (single line)
    cin>> firstname>> streetName; // input is captured in firstname & streetName string variables

    cout<< "Enter your age: "; // outputing line to terminal
    cin>> age; // input is stored in age int variable

    cout<< "Enter your street number, name, and type: "; // outputting line to terminal
    cin>> streetNum>> lastname>>streetType; //input is stored in streetNum, lastname, and streetType variables

    cout<< "Enter your city of birth: "; // outputting line to terminal
    cin>> firstname; //input is stored in firstname string variable

    newAge = (streetNum%age)*3; // calculation for newAge
    newStreetNum = (age*425)/streetNum; // calculation for newStreetNum
    newStreetName = lastname; // assigning newStreetName to lastname

    cout << endl<< "Your penname name is "<<firstname<< " "<<lastname<<"."<<endl; // outputting penname to terminal
    cout << "You will write as a "<<newAge<<" year old."<<endl; // outputting new age to terminal
    cout << "Your address is "<<newStreetNum<<" "<<streetName<< " "<<streetType<<"."<<endl; //outputting new address to terminal





}