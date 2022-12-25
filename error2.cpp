// Error checking with integers
// .good(),.fail() are good to use
// .eof() is tricky 

#include <iostream>
#include <limits> // This is important

using namespace std;

int main() {
    cout<< "Enter two integers: "<<endl;
    int input1,input2;
    cin >> input1;
    cin >> input2;

    while (!cin.good()) {
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
        // ask again
        cout << "FAILED"<< endl;
        cout<< "Enter two integers: "<<endl;
        cin >> input1;
        cin >> input2;
        
    }
    cout << "You entered "<<input1<< " "<<input2<<endl;
    
}

