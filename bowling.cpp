/* Program Name: bowling.cpp
Student Name: Jon Calvin Wetzel
Net ID: jwetzel2
Student ID: 000625680
Program Description: bowling.cpp is a program that accepts an unlimited number of players for the game of bowling. After taking the inputted scores 
for each player, the program finds their total score, outputs the winner's score, output's the loser's score, and determines who won and lost the game.
*/
#include <iostream> // including necessary libraries
#include <iomanip>
#include <vector>

using namespace std;

int main(){ // main function
    vector <string> player_names; // declaring string vector of player names
    string name; // declaring a string to store an individual player's name
    int frame, roll_value; // declaring integer variabels for the frame and roll_value [0-10]
    vector <int> total_score; //declaring a vector of integers for total scores of each player
    cout << "Enter player's name (done for no more players): "; // asking for first player's name
    cin >> name; // records input into name variable
    if (name == "done") { // if the first player is done; end the program
        cerr << "No players were entered."<< endl;
        return 1;
    }
    
    player_names.push_back(name); // if name is not none, send the name to the player name's vector

    while (name != "done") { // while loop if player's name is not done; allows for an unlimited number of players
        vector <int> roll_scores(21,0); // declaring a vector of integers for storing the score of each roll (total of 21 potential roles); all 21 elements initialized to 0
        int score =0, j=0; // initializing score at 0; and j (roll index value) to 0

        for (int i = 0; i <10; i++) { // for loop for the number of frames (10 total frames); i represents the frame value
            int k = 1; // initializing k (roll number within that frame) to equal 1 (first roll of frame)
            cout << "Enter score for frame "<<i+1<<", roll "<< k <<": "; // asks user for roll score for particular frame
            cin >> roll_value; // records value in roll value
            if (i ==9 && roll_value == 10){ // if its the 10th frame and person gets a strike
                roll_scores[j] = roll_value; // store value of strike 
                cout << "Enter score for frame "<<i+1<<", roll "<<k+1 <<": "; // has a second roll
                cin >> roll_value;
                j +=1; // increase roll index by one
                roll_scores[j] = roll_value;  
                cout <<"Enter score for frame "<<i+1<<", roll "<<k+2 <<": "; // earns a 3rd "bonus" roll because of the original strike
                cin >> roll_value;
                j+=1;
                roll_scores[j] =roll_value;
                continue;  // don't complete rest of loop and go back to top of while loop
            }

            if (roll_value < 10) { // if roll value is less that 10 (not a strike)
                roll_scores[j] = roll_value; 
                cout << "Enter score for frame "<<i+1<<", roll "<<k+1 <<": "; // ask for value of second roll for that frame
                cin >> roll_value;
                j+= 1;
                roll_scores[j] = roll_value;
                j+=1;
                if (i == 9 && (roll_scores[j-2] + roll_scores[j-1] == 10)) { // if the 10th frame and the user gets a spare (total of 10 pins for first and second rolls) then award a 3rd "bonus" roll
                    cout << "Enter score for frame "<<i+1<<", roll "<<k+2 <<": "; // bonus roll
                    cin >> roll_value;
                    roll_scores[j] = roll_value;
                    
                    continue; // don't complete rest of loop and go back to top of while loop
                }
                continue; // don't complete rest of loop and go back to top of while loop
            }

            if (roll_value == 10 && i != 9) { // for frames 1-9; if the user gets a strike
                roll_scores[j] = 10; // store value
                j += 1; // increase roll index by one
                if (k==1) { // if the strike was on the first roll of that frame
                    roll_scores[j] = 0; // the second roll of the frame must be zero (for now; the array of roll scores is adjusted later to account for strikes and spares)
                    j+=1;
                }
                continue; // don't complete rest of loop and go back to top of while loop
            }   
        } // end of frame for loop

        for (int i=0; i < 18;i++) { // correcting roll scores vector (accounting for affects of strikes and spares) 
            if (roll_scores[i] == 10 && roll_scores[i+1] ==0 && roll_scores[i+2] == 10) { // if a strike followed by another strike
                roll_scores[i+1] = roll_scores[i+2]+roll_scores[i+4];
            }
            else if (roll_scores[i] == 10 && roll_scores[i+1] ==0 && roll_scores[i+2] !=10 ) { // if a strike followed by non strike
                roll_scores[i+1] =roll_scores[i+2]+roll_scores[i+3];
            }
            if (i % 2 == 0 && (roll_scores[i]+roll_scores[i+1] ==10)) { //if a spare
                roll_scores[i+1] += roll_scores[i+2];
            }
        }
        
        for (int i=0; i <21; i++) { // summing the scores of the roll scores vector and storing it in score variable
            score += roll_scores[i]; 
        }
    
        total_score.push_back(score); // send total score of that player to the total_score vector for all players
        cout << "\nEnter player's name (done for no more players): "; // ask for the next player's name
        cin >> name; // store name in name variable
        if (name != "done") { // if the name is not "done" then send the name to player_names vector
            player_names.push_back(name);
        }
       
    } // end of while loop for player's names

    //Determining which player has lowest score and which player has the highest score (accounts for ties as well) (remember there is pontential for unlimited players)
    vector <int> max = {total_score[0]}; // initializing max vector as the first total score value (total score of the first player)
    vector <int> min = {total_score[0]}; // initializing min vector as the first total score value (total score of the first player)
    vector <int> max_index = {0}; // initialzing max index to 0 (index of the first player)
    vector <int> min_index = {0}; // initializing min index to 0 (index of the first player)

    for (int i = 0; i< player_names.size()-1; i++) { // for loop that loops throug the player names and total score vectors
        if (total_score[i+1]> max[i]) { // if the next total score value (next player) is greater than the current total score value (current player)
            max.resize(0); // resize the max vector to 0 incase there were already max values stored
            max[i] = total_score[i+1]; // set the max value to the current player total score value
            max_index.resize(0); // resize the max_index vector to 0 incase there were already max indeces stored
            max_index[i] = i+1; // set the max_index value to the current index value 
        }
        if (total_score[i+1]<min[i]) { // if the next total score value (next player) is less than the current total score 
            min.resize(0); // resize the min vector to 0 in case there were already min values stored
            min[i] = total_score[i+1]; // set the min value to the current player's total score value
            min_index.resize(0); // resize the min_index vector to 0 in case there were already min indeces stored
            min_index[i] = i+1; // set the min_index value to the current index value
        }
        if (total_score[i+1] == max[i]) { // if the current max is equal to the next player's score
            max[i+1] = total_score[i+1]; // add the next player's score value to the max vector (now multiple max values) e.g. 300 and 300
            max_index[i+1] = i+1; // add the next player's index to the max index vector (now multiple indeces)
        }
        if (total_score[i+1] == min[i]) { // if the current min is equal to the next player's score
            min[i+1] = total_score[i+1]; // add the next player's score value to the min vector (now multiple min values) e.g. 122 and 122
            min_index[i+1] = i+1; // add the next player's index to the min index vector (now multiple indeces)
        }
    }

    cout << "\n"; // output a blank line
    cout << player_names[max_index[0]] << " scored " << total_score[max_index[0]] << "."<< endl; // output the player with the max score and their score
    cout << player_names[min_index[0]] << " scored " << total_score[min_index[0]] << "."<< endl; // output the player with the min score and their score
    cout << player_names[min_index[0]] << " did the worst by scoring " << total_score[min_index[0]] << "."<< endl; // output the loser of the game and what they scored
    cout << player_names[max_index[0]] << " won the game by scoring " << total_score[max_index[0]] <<"."<< endl; // output the winner of the game and what they scored
} // end of main() function