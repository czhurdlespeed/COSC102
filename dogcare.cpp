/* Dogcare.cpp 
   Have a database of dogs to keep track of their stats and
   another dog they get along with. */
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Dog {
    public:
        string name;
        string breed;
        int age;
        Dog *bff;
};

int main() {
    Dog *d;
    vector <Dog *> database;

    /* Allocate memory for a new Dog and has d point to it.
       This memory is guaranteed to exist until either the 
       program ends, or you explicitly call delete on the pointer. */
    d = new Dog;
    d->name = "Silvie"; // NOTE: using -> to access public fields/methods in a class because 'd' is a ptr
    d->breed = "Husky";
    d->age = 7;
    d->bff = NULL;

    database.push_back(d);
    //database[0]

    /* If I did NOT push back Silvie into the database, and I continued on with the code below,
       then I would loose all contact with Silvie because of re-using 'd' with a new call. 
       This is called a MEMORY LEAK. 
       That memory (Silvie) would NOT be deallocated until the program ended,
       but no part of the program would be able to access b/c we have no "grab" on it anymore. 
       You want to avoid memory leaks, but esp when writing programs
       that will be run for a long time! think firefox - I close it about 1x month. */
    d = new Dog;
    d->name = "Winston";
    d->breed = "Corgi";
    d->age = 4;
    d->bff = database[0];

    database.push_back(d);
    
    //Set Silvie's bff to Winston
    database[0]->bff = d; //database[0]->bff = database[1]; is also legit

    for (int i = 0; i < database.size(); i++) {
        cout << "Dog " << i << " in database is ";
        cout << database[i]->name << endl;
        cout << "This dog gets along with " << database[i]->bff->name;
        cout << endl;
    }

    d = new Dog;
    d->name = "Rover";
    d->breed = "Lab";
    d->age = 2;
    d->bff = database[0];



    // dog object called rover (declared Dog rover), then I would access
    /*
    // Playing around with a Dog object (rover) and a pointer to a different Dog obj (d)
    Dog rover;
    rover.name = "Rover";
    rover.name = "Peyton";
    cout << rover.name << endl;

    d->name = "Roo";
    d->name = "Barky";

    cout << d->name << endl;
    cout << d->age << endl;
    cout << d->breed << endl;
    cout << d->bff << endl;
    */
}