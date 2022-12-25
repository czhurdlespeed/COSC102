#include <iostream>
using namespace std;
char toLowercase(char uppercase) {
    //uppercase and change it to lowercase and return
    return uppercase + 32;
}

int main() {
    cout << "hello" << endl;
    char letter = 'a' +1;
    cout<< letter << endl;
    toLowercase('B');
}

// 1. Data Sizes
 // Integer -- 4 bytes (1 byte = 8 bits)
 // short -- 2 bytes
 // float -- 4 bytes
 // doubles -- 8 bytes

 // uint8 (unsigned (can't hold negative numbers), integers, 8 bits)
 // uint32 (unsigned (can't hold negative numbers), integers, 32 bits)

// 2. Searching and Sorting Algorithms (Linear, Binary) (Bubble, Selection, Insertion)

// 3. Number Systems (Binary, hex, Decimal, Octal)
 // a. Converting between Binary, hex, and Decimal (Like the quiz)
 // b. &, |, ~, ^, <<, >> (binary operations)

// 4. Applications
 // a. bit masking 
 // b. chmod
 // c. ascii table (don't need to memorize the ASCII table!)