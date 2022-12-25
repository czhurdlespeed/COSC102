/* Mini Golf Program 
Will take in scores from 2 players in mini golf 
*/

// Put comments before each task (conditionals, while loops, etc.)
// 09/01/2022
// CS102
// Class Mini Golf Practice File
// Calvin Wetzel


#include <iostream>


using namespace std;

int main() {
    /* If you use the camelCase naming convention, use it everywhere in your file */
    string name1, name2;
    int numOfHoles =3;
    int p1holes = 0;
    int p2holes = 0;
    int data;
    
    cout<< "Please enter Player 1's name: ";
    cin>> name1;
    cout<< "You entered: " << name1 <<endl;

    cout<< "Please enter Player 2's name: ";
    cin >> name2;
    cout << "You entered: "<< name2 << endl;

    for (int i=0; i<numOfHoles; i++) {
        cout << "Please enter " <<name1 << "'s score for hole " <<i+1<< ": ";
        cin >> data;
        p1holes += data;
        cout << "Please enter " <<name2 << "'s score for hole " <<i+1<< ": ";
        cin >> data;  
        p2holes += data;

    }
    cout<< "Player 1 ("<<name1<< ") scored a "<<p1holes<<"."<<endl;
    cout<< "Player 2 ("<<name2<< ") scored a "<<p2holes<<"."<<endl;
    
    if (p1holes < p2holes){
        cout<<"Congrats "<<name1<< " - you won the game."<<endl;
    }
    else if (p1holes == p2holes){
        cout<<"This game will end in a tie!"<<endl;
    }
    else {
        cout<<"Congrats "<<name2<< " - you won the game.\n";
    }
    
}