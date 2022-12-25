// Marathon Pace Calculator
// User enters hours and minutes of a goal Marathon
// Program will return the necessary pace
// Marathon is 26.2 mi (min/mile pace) (M)M:SS
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int hour_goal;
int min_goal;
int pace_min;
double pace_sec;
int total_sec;
double marathon_dis =26.2;

int main() {
    
    printf("What is your marathon goal?\n");
    cout << "Hours: "<< endl;
    cin>> hour_goal;
    cout << "Minutes: " <<endl;
    cin>> min_goal;
    printf("Your marathon goal is %d:%02d.\n",hour_goal,min_goal);
    total_sec = min_goal*60 + (hour_goal * 60*60);
    pace_sec = total_sec / marathon_dis;
    printf(pace_sec);
  
    pace_min = pace_sec / 60;
    pace_sec = pace_sec % 60;
    
    

    cout<< setfill('0') << setw(1)<<pace_min<< ":"<<setfill('0') <<setw(2) <<pace_sec;
    cout << " min/mile." <<endl;

    

}