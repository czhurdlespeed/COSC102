#include <iostream>
using namespace std;

class Marathon {
    public:
        int hours;
        int minutes;
    private:
        string totalTime;
    
}; //must have semi colon at end of class


class Location { //atrributes/methods are private by default
    public:
        string city;
        string state;
}; 

struct Location_struct{ // attributes/methods are public by default
    string city;
    string state;

};

int main() {
    Marathon boston; // boston is instace of the Marathon Class
    Location racelocation;
    Location_struct meetlocation;
    boston.hours =3; // able to use the dot operator to access hours
    boston.minutes = 30; // and minutes because those attributes are public
    racelocation.city = "Boston";
    racelocation.state = "MA";
    meetlocation.city = "Boston";
    meetlocation.state = "MA";
    cout << "Hello World" << endl;
    cout << boston.hours << ":"<< boston.minutes << endl;
    cout << meetlocation.city << "," << meetlocation.state <<endl;
    
    
}