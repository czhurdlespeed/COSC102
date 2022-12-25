/* Time Zone Conversion Calculator */
/* Converting from Pacific to Eastern */

#include <iostream>
#include <iomanip> 
using namespace std;
int main() {
    // 3 hour difference
    // time (int hours, int minutes)
    // convert time to eastern - mod 13%12 =1...2%12 = 2
    // Print out the timeas HH:MM
    // "The time converted to Eastern time is HH:MM" <- setfill(char), setwidth(int)

    int hours;
    int minutes;
    int eastern_hour;
    

    cout << "Pacific time in hours: "<<endl;
    cin>> hours; 
    cout << "Pacific time in minutes: " <<endl;
    cin>> minutes;

    eastern_hour = hours +3;
    if (eastern_hour >= 12) {
        if (eastern_hour > 12) {
            eastern_hour = eastern_hour % 12;
        }
       
        printf("Your eastern time is: %02d:%02dpm.",eastern_hour,minutes);
    }
    // Set fill and set width version
    //cout << setfill('0') <<  setw(2) << eastern_hour << ":" <<setw(2) << minutes;
    // cout<< "." << endl;
    else {
        printf("Your eastern time is: %02d:%02dam.",eastern_hour,minutes);
    }
   
}