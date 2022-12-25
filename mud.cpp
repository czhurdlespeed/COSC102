/* Program Name: mud.cpp
Student Name: Jon Calvin Wetzel
Net ID: jwetzel2
Student ID: 000625680
Program Description: mud.cpp (Lab 9) 

ETHAN (TA) HELPED ME DEVELOP THE FLAG FOR THE MOVE METHOD AND THE RETURN FOR THE QUIT METHOD

You will be developing one of these text-based games by reading in a single file that contains a variable number of room descriptions (format of the file follows below).

First, your program will need to read a rooms file, whose name will be given as the first user-supplied command line argument. You must dynamically allocate all memory associated with the rooms file. Furthermore, the rooms file must be completely read into memory, and then the file must be closed before the game starts.

After all the rooms are read, you will place the user in the very first room (index 0) and provide them with a command line where they may enter one of six commands:

q - Quit (closes the program)
l - Look (looks at the room the player is in)
n, e, s, w - Moves the user in the given cardinal direction (north, east, south, or west).
   *If the room does not have an exit in the given direction, you must not move the player, but rather give them
   an error message. There is only ONE exit per direction.

The "look" command will print the room information. An example of this information might be:

Short Room Title
Description of Room

Exits: n e s w  ***(Only display the exits that exist in the room)***
*/

#include <string> // includig required libraries
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

struct room { // structure definition to hold information about each room
    string title, description, exits; 
};
struct exits { // structure definition to hold information about each room's exit
    string direction;
    string room_num;
};
class Mud { // Mud class definiton
    public:
        int position = 0; // starting position of user is in first room
        room *rooms; // creating rooms pointers for room structure 
        exits *exit; // creating exit pointers for exits structure
        Mud(string file); // class constructor 
        void Look(); // class Look() method
        void Move(char user_direction); // class Move() method
        int Quit(); // class Quit() method

};

Mud::Mud(string file) { // Mud class constructor definition
    ifstream fin; // using fstream library; fin is the input file stream
    string line; // string to hold fin output
    fin.open(file); // open file using file stream fin
    int tilde_counter = 0; // tilde_counter used to count # of ~ in the file
    int num_rooms; // declaring num_rooms variable
    while (getline(fin,line,'~')) { // while lines of text still exist in the file (using getline() to advance lines; getline() stops at every ~)
        tilde_counter +=1; //ran into ~; increase tilde_counter by one
    }
    num_rooms = tilde_counter/3; // equation to solve for the number of rooms in the file
    rooms = new room[num_rooms]; // initializing rooms pointer to new room structures; number of new structures is equal to number of rooms in file
    exit = new exits[num_rooms]; // initializing exit pointer to new exits structures; number of new structures is equal to number of rooms in file
    fin.clear(); // clear the file stream
    fin.seekg(0); //return the file stream position to the beginning of the file
    int room_index =0; // initializing room_index to the beginning i.e. 0
    while (getline(fin,line,'~')) { // while lines of text still exist in the file (using getline() to advance lines; getline() stops at every ~)
        rooms[room_index].title = line; // the first line of information contains the title; set the structure's title at that room's index equal to the line of information
        getline(fin,line); // advance past \n character following the ~
        getline(fin,line,'~'); // read the next line until the ~
        rooms[room_index].description = line; // this line of information contains the description; set the structure's description at that room's index equal to the line of information
        getline(fin,line,'~'); // read the next line until the ~
        rooms[room_index].exits = line; // this line of information contains the exits; set the structure's exits at that room's index equal to the line of information
        getline(fin,line); //advance past \n character following the ~
        room_index += 1; // increase the room_index by one; ascending room by room through the file
    }
    fin.close(); // closes the file stream
    // These comments contain code that would output the information contained by each room structure and pointed to by the rooms pointer
    // for (int i = 0; i < num_rooms;i++) { // display room information to console
    //     cout << "Title: " <<rooms[i].title;
    //     cout << "Desc: " << rooms[i].description;
    //     cout << "Exits: " << rooms[i].exits;
    //     cout << '\n';
    //}
    for (int j = 0; j< num_rooms; j++) { // for loop to look through each room structure
        istringstream sin(rooms[j].exits); // using sstream library with sin as string stream
        string single_dir; // declaring string to hold the string's directions
        string single_num; // declaring string to hold the string's room numbers
        while (sin >> single_dir >> single_num) { // while the string still has two values separated by ' '
            exit[j].direction += single_dir + ' '; // exits structure's direction at the room's index is set to the single_dir using the exit pointer
            exit[j].room_num += single_num + ' '; // exits structure's room number at the room's index is set to the single_num using the exit pointer
        }
    }
    // These comments contain the code used for outputting the information held by the exits structures and pointed to via the exit pointers
    // for (int k = 0; k < num_rooms;k++) { // display exit information to console
    //     cout << exit[k].direction<< endl;
    //     cout << exit[k].room_num << endl;
    // }
}

// // Look Method
void Mud::Look() { // Look() method declaration
    cout << rooms[position].title; // outputs the room's title at the user's position
    cout << rooms[position].description << endl; // outputs the room's description at the user's position
    cout << "Exits: " <<exit[position].direction << endl; // outputs the room's exits at the user's position
}

// Move Method
void Mud::Move(char user_direction) { // Move() method declaration
    char str; // declaring char variable
    istringstream my_stream(exit[position].direction); // using sstream library and my_stream as string stream
    int cycles = 1; // initializing cycles variable; used to keep track of how many times the while loop loops
    int flag = 0; // initializing flag variable; used to determine if the user_direction is one of the available exits for the room
    // ETHAN (TA) HELPED ME FIGURE OUT HOW TO DETERMINE WITH INVALID DIRECITON IS GIVEN BY USER BASED ON AVAILABLE EXITS, HENCE THE FLAG VARIABLE
    while (my_stream) { // while my_stream is true
        my_stream >> str; // first character in my_stream stored in str; then mystream advances to next character
        if (str == user_direction) { // if the str character matches the user_direction
            flag =1; // set the flag equal to 1 i.e. user_direction is valid
            break; // break the while loop because we found a match
        }
        cycles +=1; // increase cycles by 1
    }
    if (flag==0) { // if the flag still equals 0; a match was not found and the user_direction is invalid for this room's available exits
        cerr << "Exit Direction Invalid" << endl; // output error message
        return; // stop the Move() method but don't quit the program
    }
    my_stream.clear(); // clears the my_stream string stream so it can be used below
    my_stream.str((exit[position].room_num)); // using the room numbers string in the exits structure
    string string_num; // declaring string variable
    for (int i=0; i < cycles; i++) { // for loop that loops as many times as the while loop above so that the string stream reaches the correct exit room number
        my_stream >> string_num; // store the first string in my_stream (first exit number) into the string_num string variable
        position = stoi(string_num); //convert the string to an integer e.g. '123' -> 123 ; using stoi; set this value to the user's position
        
    }
    switch(str) { // switch statment used to determine output based on user's direction 
        case ('n'): // north case
            cout << "You moved NORTH." << endl; 
            break;
        case ('s'): // south case
            cout << "You moved SOUTH." << endl;
            break;
        case ('w'): // west case
            cout << "You moved WEST." << endl;
            break;
        case ('e'): // east case
            cout << "You moved EAST." << endl;
            break;
        default: // if 'n','s','e','w' not the user's direction; then they inputted an invalid letter direction
            cout << "That is not an available direction." << endl;
            break;
    }
    
}
// Quit Method
int Mud::Quit() { // Quit() method declaration
    delete[] rooms; // deallocates rooms memory (new room structures)
    delete[] exit; // deallocates exit memory (new exits structures)
    return 1; // returns 1 to quit program; ETHAN (TA) HELPED ME FIGURE OUT WHAT I NEEDED TO RETURN TO QUIT THE PROGRAM
}

int main(int argc, char **argv) { // using command line arguments to provide the file name for the program
    char command; // declaring char variable 
    Mud mud1(argv[1]); // new Contructor with mud1 and argv[1] in the command line as the file
    mud1.Look(); // class Look() method to display the user's starting room (the first room)
    while (true) { // loops while the while loops is true
        cout << "> ";
        cin >> command; // user input stored in command char variable
        switch (command) { // switch statement for user commands
            case ('q'): // user command is quit
                mud1.Quit(); // call the Quit() method
                return 1; // stop the program
            case ('l'): // user command is look
                mud1.Look(); // call the Look() method
                break;
            case('n'): // user command is north
                mud1.Move('n'); // call the Move() method with 'n' as argument
                break;
            case('e'): // user command is east
                mud1.Move('e'); // call the Move() method with 'e' as argument
                break;
            case('w'): // user command is west
                mud1.Move('w'); // call the Move() method with 'w' as argument
                break;
            case('s'): // user command is south
                mud1.Move('s'); // call the Move() method with 's' as argument
                break;
            default: // else an invalid command was given
                cout << "Invalid Command" << endl;
                break;
        }
    }
}
