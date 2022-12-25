// I/O (Input/Output) Manipulation
#include <iostream>
#include <iomanip>
using namespace std;
 

// printf()
// Specifiers f -> floats, s-> strings, d-> int, c->chars Ex) printf("My dog is %s.", name.c_str() or printf("My grade is %.2f.",grade))
//c_str() converts characters to string (C++ doesn't recognize strings; just characters but string is array of characters)
// cout << "MGI"<<fixed<<setprecision(2)<<grade<<endl;
// fixed, scientific, hex
// setw() set width
// setfill() place a character; useful for printing out time data (adding colons/periods)
int main(){
    cout<< setprecision(2);

    int i =10;
    double d = 20.2526;
    double d2 = 35.789;

    cout << i<< " "<< d<<" "<< d2<<endl;

    printf("%2", d2);

    cout << setw(10)<<i<<" "<<d<<endl;



}