#include <iostream>
#include <string>
using namespace std;


string ToBinary(int bit_set, int spacing) {
    string ret;
    // TODO: Add values to the ret string. The constructor will
    // clear it to the empty string "".
    for (int i = 31;i >= 0;i--) {
        // TODO: Write the logical operation that tests the bit at index i
        if ((bit_set >> i) & 1) { 
            ret += '1';
        }
        else {
            ret += '0';
        }
        // TODO: Check to see if we need a space here.
        if (i> 0 && i % spacing == 0) {
            ret += ' ';
        }
    }
    return ret;
    }


int main() {

    cout <<ToBinary(122,4) << endl;
}
