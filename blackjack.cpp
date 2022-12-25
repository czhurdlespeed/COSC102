/* Program Name: blackjack.cpp
Student Name: Jon Calvin Wetzel
Net ID: jwetzel2
Student ID: 000625680
Program Description: blackjack.cpp is a program that replicates the game of blackjack (Aces count as 1)
*/
#include <iostream> // including libraries
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <array>
#include <cstdlib>
#include <ctime>


using namespace std; //using namespace standard

const string numbers[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"}; // initialzing numbers array
const string suits[4] = {"C","D","H","S"}; // initializing suits array

int GetRandom(int min, int max) { // GetRandom function definition: finds random number between a range; in this case the indices of the deck of cards [0,51]; takes two integers as parameters
    int random_num = rand() % (max-min)+min;
    return random_num;

}

string DealCard( int my_array[52], string Player) { //DealCard Function definition: return the random card dealt to respective individual; also uses array to keep track of which player has each card; takes 52 element array and a string as parameters
        
        int card_array_index, suit_index, numbers_index; // defining variables
        string drawn_card; // defining drawn_card
        
        card_array_index = GetRandom(0,51); // get random card index from deck of cards
       
        suit_index = card_array_index % 4; // since it is single array; the modulus 4 is to determine the suit index; reference suits array
        numbers_index = card_array_index % 13; // since it is a single array; the modulus 13 is to determine the number/face; reference number array
        while (my_array[13*suit_index+numbers_index] != 0) { // while the drawn card is already held by a player/dealer
            card_array_index = GetRandom(0,51); // pick another random card index
            suit_index = card_array_index % 4; // find suit index
            numbers_index = card_array_index % 13; // find number index

        }
        if (my_array[13*suit_index+numbers_index] == 0 && Player == "Player"){
            my_array[13*suit_index+numbers_index] = 1; // if the card is not already held; and the player is Player; assign 1 to the index of the 52 element zero array; (Player's mark)
        }
        if (my_array[13*suit_index+numbers_index] == 0 && Player == "Dealer"){
            my_array[13*suit_index+numbers_index] = 2;// if the card is not already held; and the player is Dealer; assign 2 to the index of the 52 element zero array; (Dealer's mark)
        }

        drawn_card = "" + numbers[numbers_index] + suits[suit_index]; //drawn card in string format using numbers and suits arrays
      
        return drawn_card; // return the string format of the drawn card

    }

int ScoreHand(int score_cards[52], string Person_to_score) { //Scores the hand held by the respective player; takes a 52 element array and string as parameters
    int hand_score =0; // initialize hand as 0
    if (Person_to_score == "Player") { // if person to score is Player
        for (int i = 0; i <4; i++) {
            for (int j = 0; j<13; j++) { // iterate through 52 element array
                if (score_cards[13*i+j] == 1) { // if element is equal to 1 (Player's mark)
                    int k = j+1; // add one (talking about card values which don't start from zero)
                    if (k<10){ // if not a face card
                        hand_score += k; // value is value of card (the number itself)
                    }
                    else { //otherwise
                        hand_score += 10; // value must be a face card = 10 pts
                    }
                }
            }
        }
    }
    if (Person_to_score == "Dealer") { // if person to score is Dealer 
        for (int i = 0; i <4; i++) {
            for (int j = 0; j<13; j++) { // iterate through 52 element array
                if (score_cards[13*i+j] == 2) { // if element is equal to 2 (Dealer's mark)
                    int k = j+1;// add one (talking about card values which don't start from zero)
                    if (k<10){ // if not a face card
                        hand_score += k; // value is value of card (the number itself)
                    }
                    else { // otherwise
                        hand_score += 10; // value must be a face card = 10 pts
                    }
                }
            }
        }
    }
    return hand_score; // return the final hand score for the respective player
}

void InitializeCards(int cards[52]) { // InitializeCards function definition: initializes cards with a defined array as a parameter; doesn't return anything
    
    for (int i=0; i<4; i++) {
        for (int j=0;j<13; j++) {
            cards[13*i+j] =0; // creates a 52 element array of zeros but uses i and j iterators as a means to create various suits with values

        }
    }
    
    
}


int main() { // main function 
    srand(time(NULL)); // must be using with rand() in c++; uses computer's time as a seed to generate random numbers
    int cards[52]; // definition of array of 52 elements
    string hit_or_stand; // string variable for cin
    string player_1, player_2, dealer_1, dealer_2; // string variables to hold cards for player and dealer
    InitializeCards(cards); // call to InitializeCards function using cards as an argument
    player_1 = DealCard(cards,"Player"); // player first dealt card
    player_2 = DealCard(cards,"Player"); // player second dealt card
    dealer_1 = DealCard(cards,"Dealer"); // dealer first dealt card
    dealer_2 =DealCard(cards,"Dealer"); // dealer second dealt card
    cout << "Dealer has cards: "<<setw(3)<<left<<dealer_1<< " "<<  setw(3) << left<< dealer_2 <<setw(14)<< right << "("<<ScoreHand(cards,"Dealer")<<")"<<endl; // first output of dealer's two initial cards
    cout <<  "Player has cards: "<<setw(3)<<left<<player_1 << " " << setw(3) << left<< player_2<<setw(14)<< right << "("<<ScoreHand(cards,"Player")<<")"<<endl; //first output of player's two initial cards
    cout << "Hit or stand    ? "; // asks if player wants to hit or stand
    cin >> hit_or_stand; // stores input in hit_or_stand variable
    cout << "\n"; // new line
    if (hit_or_stand == "hit") { // if player selects hit
        cout << "Dealer has cards: "<<setw(3)<<left<<dealer_1<<" "<< setw(3) << left<< dealer_2 <<setw(14)<< right << "("<<ScoreHand(cards,"Dealer")<<")"<<endl; // output dealer's two initial cards again
        cout <<  "Player has cards: "<<setw(3)<<left<<player_1 << " "<< setw(3) << left<< player_2<< " "<<setw(3)<<left<<DealCard(cards,"Player")<<setw(10)<< right << "("<<ScoreHand(cards,"Player")<<")"<<endl; // output player's two inital cards again plus third new card
        if (ScoreHand(cards, "Player")>21) { // if the player's 3 cards exceeds 21
            cout << "Player busts, dealer wins!"<<endl; // player loses
            return 0; //program complete
        }
    }
    if (ScoreHand(cards,"Dealer")<18) { //if the dealer's first two cards are less that 18pts, then the dealer will hit
        cout <<"\n"<<"Dealer hits     : " << setw(3)<<left<<dealer_1<< " "<<setw(3)<<left<<dealer_2<< " "<<setw(3)<<left<<DealCard(cards,"Dealer") << setw(10) << right << "("<<ScoreHand(cards,"Dealer")<<")"<<endl; // output dealer's two initial cards again plus third new card 
        if (ScoreHand(cards, "Dealer")>21) { // if dealer's 3 cards exceed 21pts
            cout << "Dealer busts, player wins!"<<endl; // dealer loses
            return 0; //program complete
        }
    }
    if (ScoreHand(cards,"Player")> ScoreHand(cards,"Dealer")){ // if player's hand score is greater than the dealer's hand score
        cout << "Player wins!\n"; //player wins
        return 0; // program complete
    }
    else if (ScoreHand(cards,"Player") == ScoreHand(cards,"Dealer")){ // if the scores are the same/equal
        cout << "Player and dealer draw."<< endl; // draw
        return 0; // program complete
    }
    else { //otherwise
        cout << "Dealer wins!\n"; // dealer must have higher score and wins
        return 0; // program complete
    }

        
    
}


