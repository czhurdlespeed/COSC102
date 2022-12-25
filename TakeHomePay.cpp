/* Program Name: TakeHomePay
Student Name: Jon Calvin Wetzel
Net ID: jwetzel2
Student ID: 000625680
Program Description: TakeHomePay takes an input salary and calculates federal taxes breakdown, take home salary, and monthly take home pay
*/
#include<iostream> // including iostream library
#include<iomanip> // including iomanip library 

using namespace std; 

double salary;    // variables declared 
double tax_salary;
double income_tax =0;
double tax_amount;
double social_tax;
double medicare;
double take_home;
double monthly_take_home;



int main() {  
    cout<< "Enter a salary: $";  // output to terminal 
    cin >> salary; // assigns input to salary 
    tax_salary = salary; // that salary is also assigned to tax_salary
    if (salary< 15080) { // conditional statement for when the salary is less than minimum wage
        cout << "This is less than minimum wage for a yearly salary."<< endl; // output to terminal
        return 1; // return 1 to indicate program finished due to an error/fault
        
    }
    cout << "-----------------------------------"<<endl; // first line of dashes
    cout << setw(25)<<left <<"Yearly Salary:"<< "$";  // Yearly Salary outputted to terminal using i/o manipulators; left justified
    cout <<  fixed<< setprecision(2) <<setw(9) << right << salary<< endl; // Yearly salary value outputted on same line but right justified; all dollar variabels have 2 decimal places (setprecision(2))
    
    if (tax_salary>=539901 ){  // conditional for highest tax bracket; move down the tax brackets from here b/c only money made above each bracket value is taxed at the respective bracket percentage
        tax_amount = (tax_salary -539900)*.37; // 37% tax rate on money above the lower limit of the tax bracket (all other brackets follow the same form)
        income_tax += tax_amount; // tax amount stored in income_tax variable which is updated throughout the brackets  e.g. +=
        tax_salary = 539900;
    }

    if (tax_salary>=215951 && tax_salary<=539900 ){ // conditional for second highest tax bracket
        tax_amount = (tax_salary -215950)*.35; // 35% tax rate
        income_tax += tax_amount;
        tax_salary = 215950;
    }

    if (tax_salary>=170051 && tax_salary<=215950 ){ // conditional for third highest tax bracket
        tax_amount = (tax_salary -170050)*.32; // 32% tax rate
        income_tax += tax_amount;
        tax_salary = 170050;
    }
    
    if (tax_salary>= 89076 && tax_salary<=170050){ // conditional for fourth highest tax bracket
        tax_amount = (tax_salary -89075)*.24; // 24% tax rate
        income_tax += tax_amount;
        tax_salary = 89075;
    }
    

    if (tax_salary>= 41776 && tax_salary <= 89075){ // conditional for fifth highest tax bracket
        tax_amount = (tax_salary -41775)*.22; // 22% tax rate
        income_tax += tax_amount;
        tax_salary = 41775;
    
    }
    if (tax_salary >= 10276 && tax_salary <= 41775) { // conditional for sixth highest tax bracket
        tax_amount = (tax_salary - 10275)*.12; // 12% tax rate
        income_tax += tax_amount;
        tax_salary = 10275;
    }
    
    if (tax_salary <= 10275) { // conditional for lowest tax bracket
        tax_amount =  tax_salary*.10; // 10% tax rate (lowest federal rate)
        income_tax += tax_amount;
    }

    social_tax = salary * 0.062; // calculation for social security tax; based on total salary
    medicare = salary * 0.0145; // calculation for medicare tax; based on total salary

    cout << setw(25)<<left <<"Social Security Tax:"<< "$";  // using i/o manipulators to create the rest of the tax table as shown in the examples; the respective vaules are assigned to each row
    cout <<  fixed<< setprecision(2) <<setw(9) << right << social_tax<< endl;
    cout << setw(25)<<left <<"Medicare Tax:"<< "$";
    cout <<  fixed<< setprecision(2) <<setw(9) << right << medicare<< endl;
    cout << setw(25)<<left <<"Income Tax:"<< "$";
    cout <<  fixed<< setprecision(2) <<setw(9) << right << income_tax<< endl;
    cout << "-----------------------------------"<<endl; // second dashed line
    cout << setw(25)<<left <<"Take Home Salary:"<< "$";
    cout <<  fixed<< setprecision(2) <<setw(9) << right << (salary-income_tax-social_tax-medicare)<< endl;
    cout << setw(25)<<left <<"Monthly Take Home Pay:"<< "$";
    cout <<  fixed<< setprecision(2) <<setw(9) << right << (salary-income_tax-social_tax-medicare)/12<< endl; // conclusion of tax data table



}