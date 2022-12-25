// switch statement program example
// program adding sensors to a watch/fitness device
// adding heartrate monitors, speed/cadence, power
#include <iostream>
#include <string>
using namespace std;

int main() {
    int sensor;

    cout<< "What sensor would you like to add? 1 - HR, 2 - Speed, 3 - Cadence, 4 - Power ";
    cin >> sensor; // read in sensor

    switch (sensor) {
        case 1:
            cout << "HR is connected."<<endl;
            break;
        case 2:
        case 3: // want same output string for Speed and Cadence selections 
            cout << "Speed/Cadence is connected."<<endl;
            break;
        case 4:
            cout << "Power is connected.\n";
            break;
        default:
            cout<< "Sensor is not recognized.\n";
        
    }
}
