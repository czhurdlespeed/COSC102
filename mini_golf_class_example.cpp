/* Mini Golf Program: Class Example
   Will take in scores from 2 players in mini golf
   THIS IS WHERE WE FINISHED CLASS on 9/1
   */
#include <iostream>
#include <vector>
using namespace std;

// Creating Function
void askForNames() {
    cout << "Please enter your name: ";
}

int sumScores(vector <int> myScores) {
    int finalScore = 0;
    for (int i = 0; i< myScores.size(); i++) {
        //sum up scores here
        finalScore += myScores[i];
    }
    // return scores here
    return finalScore;
}

int main() {
   string name1, name2;
   int numOfHoles = 3;
   int strokes; // temporary data, reused for each hole
   int score1 = 0;
   int score2 = 0;
   int playerNum; // 1 or 2 or 0 - use this to catch which player has incorrect data
   
    
   //Vector Pratice using .size, .clear, and indexes []

   vector <int> player1holes;    // int is the data type stored in vector container
   vector <int> player2holes;
    /*
   cout << "The vector is size " <<player1holes.size() <<endl; 
   player1holes.push_back(5);
   cout << "The score for Player 1's hole 1 was: " <<player1holes[0] << endl;
   cout << "The vector is size " <<player1holes.size() <<endl;
   player1holes.clear(); 
   cout << "Clearing the vector, it's now size: " << player1holes.size() << endl;
    */ 


   /* Read in player names from the user */
   //cout << "Please enter Player 1's name: ";
   askForNames();
   cin >> name1;
   cout << "You entered: " << name1 << endl;
   //cout << "Please enter Player 2's name: ";
   askForNames();
   cin >> name2;
   cout << "You entered: " << name2 << endl;
   
  
  
   /* Store and sum up the scores from each hole */
   for (int i = 0; i < numOfHoles; i++) {
      

      cout << "Please enter " << name1 << "'s score for hole " << i + 1 << ": ";
      cin >> strokes; 
      // WE USE THE VECTOR   
      player1holes.push_back(strokes);

      //score1 += strokes; 
      cout << "Please enter " << name2 << "'s score for hole " << i + 1 << ": ";
      cin >> strokes;
      player2holes.push_back(strokes);
      //score2 += strokes;
   }

   /* Calculate the final score by summing the data in the vector */
   // Using .size() in a for loop but not great programming practice b/c assuming play holes are the same size
   /*for (int i = 0; i< player1holes.size(); i++) {
        score1 += player1holes[i];
        score2 += player2holes[i]; 

    }*/
   score1 = sumScores(player1holes);
   score2 = sumScores(player2holes);

   /* Print final scores for each player */
   cout << "Player 1 (" << name1 << ") scored a " << score1 << "." << endl;
   cout << "Player 2 (" << name2 << ") scored a " << score2 << "." << endl;
   /* Reveal the winner of the game */
   if (score1 < score2) { 
      cout << "Congrats " << name1 << " - you won the game!" << endl; 
   }
   else if (score1 == score2) {
      cout << "Tied game!" << endl;
   }
   else {
      cout << "Congrats " << name2 << " - you won the game!" << endl;
      //printf("Final score %d - you won the game", score2); // c function
   }
}
//262095