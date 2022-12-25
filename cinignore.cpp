/* Error checking
REad in doubles, and if the user types in something other than
a double, refuse that entry.
REMEMBER: 3,4,10, etc. are doubles. Whole numbers are stored as 3.8,4.0...
*/

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

void ignoreLine(){
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    //(number of characters to ignore (X), extraction operator)
    // we ignore X number of characters or until we see the extraction operator
}

// Classes must be created before int main() {}

int main() {
    while (true) {// loop unitl user enters a valid input
        cout << "Enter a double value: ";
        double x;
        cin>> x;

    if (!cin) {// has a previous extraction failed? (cin is not a double as we declared for variable x)
        cin.clear(); // put us back in 'normal' operation mode (get us out of failure state)
        ignoreLine(); // and remove bad input
        cout << "Fail" << endl;

    }
    else { //else our extraction succeeded
        ignoreLine();
        cout << x << endl; // so return the value we extracted
        break;


    }
    }
}
