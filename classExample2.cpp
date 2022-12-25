/* HEADER */
#include <iostream>
using namespace std;

class Car {         // the class
  private:          // access specifier
    string brand;   // attribute
    string model;   // attribute
    int year;       // attribute
  public:           // access specifier
    Car(string b, string m, int y);   // constructor signature
    void printCarInfo();              // void method
    int addYear();
};

Car::Car(string b, string m, int y) { // constructor definition
  brand = b;
  model = m;
  year = y;
}

void Car::printCarInfo() {               // void method definition
  cout << year << " " << brand << " " << model << endl;
}

int Car::addYear() {
  //year++;
  return (year + 1); // year++ - value grab of year, then addition vs ++year - addition, then the value grab
}

int main() {
  Car myFirstCar("Honda", "Accord", 2008);
  Car anotherCarObj("Ford", "Mustang", 2001);

  myFirstCar.printCarInfo();
  anotherCarObj.printCarInfo();

  int a = myFirstCar.addYear();
  cout << a << endl;
}