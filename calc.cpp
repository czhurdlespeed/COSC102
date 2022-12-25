// Lab 03 Calculator
// COSC102
// Jon Calvin Wetzel
// NETID: jwetzel2
// UTID: 000625680

// Calculator

#include <iostream> // including libraries 
#include <limits>


using namespace std;

int main(){

    int left_operand; // declaring left_operand as int
    char operation;   // declaring operation as string
    int right_operand; // declaring right_operand as int

    cout << "Enter left operand: "; // outputting to console
    cin >> left_operand; // recording input for left_operad
    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // ignoring input after first inputted value
    if (cin.fail()){ // if inputted value does not match the declared variable type then enter the conditional
        cout << "Invalid left operand." << endl; // output to console if conditional is entered
        return 1; // finish program
    }

    cout << "Enter operation: "; // outputting to console
    cin >> operation;   // recording input for operation
    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // ignoring input after first inputted value
    switch(operation){ // switch statement with operation as variable
        case 'B': // cases for absolute operation (in separate switch statement becasue it doesn't require right operand)
        case 'b':
        case '|': 
            cout<< "Result = "<< left_operand*-1 <<endl; // output if absoluted operation is selected
            return 0; // finish program     
    }

    cout << "Enter right operand: "; // outputting to console
    cin >> right_operand; // recording input for right_operand
    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // ignoring input after first inputted value
    if (cin.fail()){ // if inputted value does not match the declared variably type then enter the conditional
        cout << "Invalid right operand." << endl; // output to console if conditional is entered
        return 1; // finish program
    }

    switch (operation){ // switch statement for remaining operations 
        case 'A': // addition cases
        case 'a':
        case '+':
            cout<< "Result = " << left_operand + right_operand << endl; // output if addition operation is selected
            break; // breaks switch statement
        case 'S': // subtraction statements
        case 's':
        case '-':
            cout<< "Result = "<< left_operand - right_operand <<endl; // output if subtraction operation is selected
            break; // breaks switch statement
        case 'M': // multiplicaiton cases
        case 'm':
        case 'x':
        case '*':
            cout<< "Result = "<< left_operand * right_operand <<endl; // output if multiplication operation is selected
            break; // breaks switch statement
        case 'D': // division cases
        case 'd':
        case '/':
            cout<< "Result = "<< left_operand / right_operand <<endl; // output if division operation is selected
            break; // breaks switch statement
        case 'C': // Modulo cases
        case 'c':
        case '%':
            cout<< "Result = "<< left_operand % right_operand <<endl; // output if modulo operation is selected
            break; // breaks switch statement
        default: // if non of the cases are met, then this is entered
            cout << "Unknown operation." << endl;  // output to console if inputted operation does not match any of the cases
    }
}








