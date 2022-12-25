/* Program Name: Lab5
Student Name: Jon Calvin Wetzel
Net ID: jwetzel2
Student ID: 000625680
Program Description: Lab5 is a speeding ticket fee calculator. This program asks for a ticket file and outputs the assoicated fine(s) 
    values if the citation number(s) fit within the user specified date range
*/
#include <iostream> // including libraries 
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main() { // entering program
    ifstream  fin; // setting fin to ifstream
    const double interstate = 5.2341, highway = 9.4826, residential = 17.1544, none = 12.8334; // multiplier values assigned 
    string ticket_file; // ticket file name
    int start_year, start_month, start_day;
    int end_year, end_month, end_day;
    string citation_num;
    int month, day, year; // citation number month, day, and year
    int speed, speed_limit; // clocked spped and speed limit
    char road_type; // road type; used in switch statement
    double fine;
    int start_date_num, end_date_num, citation_date_num; // variables created to transform dates into comparible numbers
  
    const  string char_month[] = {"Jan", "Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"}; // constant array initialized with month abbreviations

    cout << "Enter a ticket file: "; // asking user for ticket file
    cin >> ticket_file;

    fin.open(ticket_file); // using fin and open() function to open the ticket file
    if (fin.fail()) { // if file fails to open enter this conditional statement
        cout << "Unable to open "<< ticket_file <<"."<<endl;
        return 1; // finish program due to error
    }
    cout << "Enter report start date (mm dd yyyy): "; // ask user for start date
    cin >> start_month>> start_day >> start_year; // sets input to associated variables
    cout << "Enter report end date   (mm dd yyyy): "; // ask user for end date
    cin >> end_month >> end_day >> end_year; // sets input to associated variables
    start_date_num = start_day + start_month*100 + start_year*10000; // transforms start date into number for comparison; weighting increases between day, month, and year (multiply by 100 for each step)
    end_date_num = end_day + end_month*100 + end_year * 10000; // transforms end date into number for comparison; weighting increases between day, month, and year (multiply by 100 for each step)

    while (fin >> citation_num >> month >> day >> year >> speed >> speed_limit >> road_type) { // while loop for reading ticket file
        if (year <100) { // if year is in yy format convert to yyyy format (assumed to be 21st century)
            year += 2000;
        }
        citation_date_num = day + month * 100 + year * 10000; // // transforms citation date into number for comparison; weighting increases between day, month, and year (multiply by 100 for each step)
        if (citation_date_num>= start_date_num && citation_date_num <= end_date_num) {
           switch (road_type) { // switch statement for road type mulitpliers
                case 'I': // interstate case
                case 'i':
                    fine = (speed-speed_limit)*interstate;
                    break;
                case 'R': // residential case
                case 'r':
                    fine = (speed-speed_limit)*residential;
                    break;
                case 'H': // highway case
                case 'h':
                    fine = (speed-speed_limit)*highway;
                    break;
                default: // none (default) case
                    fine = (speed-speed_limit)*none;
            } 
            if (fine < 0) { // if fine is negative, make fine equal to 0
                fine =0;
            }
            cout << setprecision(2) <<fixed<< setw(10) << left << citation_num << setw(2) << setfill('0') << right;
            cout <<  day << '-'<<char_month[month-1] <<'-'<<year <<" $"<<setfill(' ')<< setw(9)<<right << fine << endl;  
            /* outputs to console citation number left justified; day with width of 2, month 
            in abbreviated form by indexing into array, and fine right justified with 2 decimal places and dollar sign */ 
        }
    }
    fin.close(); // close ticket file
}