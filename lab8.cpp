/* Program Name: lab8.cpp
Student Name: Jon Calvin Wetzel
Net ID: jwetzel2
Student ID: 000625680
Program Description: lab8 is a program that allows a user to set, print, clear, and test integers of a vector via binary operations. 
The binary operations can be used to alter (addition/subtraction) an element (integer) of the vector, add to the vector (resize), or subtract from the vector (resize).
*/
#include <iostream> // including various libraries
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std; 

class BITSET { // class declaration
    vector<int> mSets; // vector of integers called mSets (private)
public: //access specifier
    BITSET(); // the BITSET class and following functions are all made public (accessible to the user)
    bool Test(int index) const;
    void Set(int index);
    void Clear(int index);
    int GetNumSets() const;
    int GetSet(int index) const;
}; // end of BITSET class declaration 

string ToBinary(int bit_set, int spacing=4); //To binary fucntion delcared (parameters are set)

int main() {
    BITSET sets; // BITSET instance; sets if the named of the vector of integers (like mSets)
    string command; // command declared (stores the command (q, s, g, t, c, etc.))
    int which; // which declared (stores the integer following the command)
    do {
        cout << "> ";
        if (!(cin >> command) || "q" == command) { // if no command given or if "q" is given as the commmand
            // If cin fails for any reason, it usually means
            // an EOF state, break and quit.
            break;
        }
        if ("t" == command) { // if command is "t"
            if (!(cin >> which)) { // if which does not exist (integer not given)
                cout << "Invalid index\n"; // output
            }
            else {
                cout << sets.Test(which) << '\n'; // else run test function with which as argument
            }
        }
        else if ("s" == command) { // if the command is "s"
            if (!(cin >> which)) { // if which does not exist (integer not given)
                cout << "Invalid index\n"; // output
            }
            else {
                sets.Set(which); // else run set function with which as argument
            }
        }
        else if ("g" == command) { // if the command is "g"
            int spacing; // delcaring integer variable spacing
            string line; 
            getline(cin, line); // read input line
            istringstream sin {line};
            if (!(sin >> which)) { // if which not given (no index)
                cout << "Invalid index\n"; // output
            }
            else {
                if (!(sin >> spacing)) { // if spacing is not inputted/provided
                    spacing = 4; //initialize spacing
                }
                cout << ToBinary(sets.GetSet(which), spacing) << '\n'; //run ToBinary Function if which is provided
            }
        }
        else if ("c" == command) { // if the command is "c"
            if (!(cin >> which)) { //if which is not provided (no integer given)
                cout << "Invalid index\n"; // ouput
            }
            else {
                sets.Clear(which); // run the clear function if which is provided 
            } 
        }
        else if ("n" == command) { // if the command is "n"
            cout << sets.GetNumSets() << endl; // run the GetNumSets() function
        }
        else {//if the command does not match any of the function letters
            cout << "Unknown command '" << command << "'\n";  //output
        }
    } while (true);
    return 0;
} // end of int main()

string ToBinary(int bit_set, int spacing) { // declaration of ToBinary Function with parameters bit_set and spacing
    string ret; // delcare a string for ToBinary
    // TODO: Add values to the ret string. The constructor will
    // clear it to the empty string "".
    for (int i = 31;i >= 0;i--) { // for loop that iterates through the 32 bits of the integer (bit_set)
        // TODO: Write the logical operation that tests the bit at index i
        if ((bit_set >> i) & 1) { // if the integer in Sets vector right shifted by i and & (binary operation) with 1 is true
            ret += '1'; // catenate '1' to the ret string
        }
        else {
            ret += '0'; // catenate '0' to the ret string
        }
        // TODO: Check to see if we need a space here.
        if (i> 0 && i % spacing == 0) { // if number of values added to ret = spacing and i is not the first value is true
            ret += ' '; // catenate ' ' to the ret string
        }
    } //end of for loop
    return ret; // return ret (binary (string) representaion of bit_set (integer in sets vector))
}
// BITSET Class Members
BITSET::BITSET() : // delcaring members of the class BITSET
   mSets(1, 0) // initilzie a vector of integers mSets with 1 element that is 0
{}

bool BITSET::Test(int index) const { //BITSET method called Test
    // Recall that each set has 32 bits
    int which_set = index / 32 ; // finding the set (position in mSets vector) based on the provided index (position in the binary representaion of the integer in mSets)
    int which_bit = index % 32  ; // finding the bit location (binary index in the binary representation of the integer) based on the index provided  
    if (which_set >= GetNumSets()) { // which_set starts at 0; if the set desired to be tested is greater than the number of elements in the vector mSets
        // The BITSET is an "infinite" set, so if the requested set
        // is bigger than what we are storing, that means it's a 0.
        return false; // return false; becauses an integer greater than zero cannot exist at that set position
    }
    // TODO: Write the code to test the bit at which_set/which_bit
    // and return true if it's a 1 or false if it's a 0.
    else if (mSets.at(which_set) & (1<<which_bit)) { // take set and left shift it by which_bit places; if it equals 1, then you know that the bit at which_set, which_bit was equal to 1
        return true; //return true (1)
    }
    else {
        return false; // 1 did not exit at the tested bit position; return 0
    } // end of conditionals 
} // end of Test Function declaration

void BITSET::Set(int index) { // Set function declaration
    int which_set = index / 32; // finding the set (position in mSets vector) based on the provided index (position in the binary representaion of the integer in mSets)
    int which_bit = index % 32 ; // finding the bit location (binary index in the binary representation of the integer) based on the index provided 
    // TODO: You might need to expand the Set to accommodate the index
    // which_set. If you do not do this properly, you will get a runtime
    // error named 'out_of_range'
    // TODO: Finish the bitwise operator to set bit which_bit.
    if (which_set+1 > GetNumSets()){ // if index is outside of range 
        mSets.resize(which_set+1); // expand mSets vector so that the desired bit location can be set
    }
    mSets.at(which_set) |= (1<< which_bit); // for the given set, set the desired bit location to 1 by using binary OR (|) with 1 left shifted by which_bit
} // end of Set function declaration

void BITSET::Clear(int index) { // Clear function declaration 
    int which_set = index/32 ; // finding the set (position in mSets vector) based on the provided index (position in the binary representaion of the integer in mSets)
    int which_bit = index % 32 ; // finding the bit location (binary index in the binary representation of the integer) based on the index provided 
    if (which_set < GetNumSets()) { // if the desired set is within the range of existing sets
        mSets.at(which_set) = mSets.at(which_set) & (~(1<<which_bit)); // clear the bit at the desired bit index location by using binary & with ~(mask); where mask is 1 left shifted by which_bit
        //ETHAN RICKERT (TA) HELPED ME DEVELOP THIS WHILE LOOP DURING OFFICE HOURS IN THE PROGRAMMING CLINIC
        while (mSets.back() == 0 && (mSets.size()>1)) { // if the last value of vector mSets is 0 and the size of the mSets vector is greater than one (contains more than just the initialize amount)
            mSets.pop_back(); //remove the 0 from the mSets vector (pruning the vector) 
        } // end of while loop
    } // end of conditional
} // end of Clear function declaration 

int BITSET::GetNumSets() const { // GetNumSets function declaration
    return static_cast<int>(mSets.size()); //returns the size of the mSets vector (number of elements in the vector)
} // end of GetNumSets vector


// DURING OFFICE HOURS IN THE PROGRAMMING CLINIC, ETHAN RICKERT (TA) HELPED ME FIX THE GETSET FUNCTION SO THAT IT COULD RUN CORRECTLY IN THE TOBINARY FUNCTION 
int BITSET::GetSet(int index) const { // GetSet function declaration; index parameter refers to the set index not the bit index!!!
    if (mSets.size()>= index+1) {  // if the set index+1 is within the range of the mSets vector size (if the set index exists within the mSets vector)
        return mSets.at(index); // return the element (integer) at the mSets index
    }
    else {
        return 0; // return zero becasue the set index does not exist within the mSets vector
    }
} // end of GetSet function declaration