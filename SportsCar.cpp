#include <iostream>
using namespace std;

class Car {
protected:
    string make;
    string model;
    int year;
public:
    Car();
    Car(string make, string model, int year);
    Car(const Car& obj);
    Car& operator=(const Car& obj);
    ~Car();
    void drive();
};
Car::Car() {}  //default constructor

Car::Car(string make, string model, int year) {
    this->make = make;
    this->model = model;
    this->year = year;
    cout << "Car Constructor called\n" << endl;
}
Car::Car(const Car& obj) {
    *this = obj;
    cout << "Car Copy Constructor called\n" << endl;
}

Car& Car::operator=(const Car& obj) {
    if (this != &obj) {
        this->make = obj.make;
        this->model = obj.model;
        this->year = obj.year;
        cout << "Car Copy Assignment Operator called\n" << endl;
    }

    return *this;
}

Car::~Car() {
    cout << "Car Destructor called\n" << endl;
}

void Car::drive() {
    cout << "Drive a " << year << " " << make << " " << model << endl;
}

class SportsCar : protected Car {
private:
    int topspeed;
public:
    SportsCar(string make, string model, int year, int spd);
    void drive();
    ~SportsCar() {
        cout << "SportsCar Destructor called\n" << endl;
    }
};

SportsCar::SportsCar(string make, string model, int year, int spd) {
    this->make = make;
    this->model = model;
    this->year = year;
    this->topspeed = spd;
    cout << "SportsCar Constructor called\n" << endl;
}

void SportsCar::drive() {
    cout<< "Drive a " << year << " " << make << " " << model << "with topspeed: " << topspeed << endl;
}

int main () {
    Car AvanteWhite("Hyundai", "Avante", 2020);
    Car AvanteBlack(AvanteWhite);
    Car AvanteGray;
    AvanteGray = AvanteBlack;  //Copy assignment operator overload

    AvanteWhite.drive();
    AvanteBlack.drive();
    AvanteGray.drive();
    cout << endl;

    SportsCar P911("Porsche", "911", 2021, 350);
    P911.drive();

    return 0;
}
