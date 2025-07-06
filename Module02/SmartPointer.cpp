#include <iostream>
#include <memory>
#include <string>
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
Car::Car() {
    cout << "Car default constructor called\n" << endl;
}  //default constructor

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

class SportsCar : public Car {
private:
    int topspeed;
public:
    SportsCar(string make, string model, int year, int spd);
    void drive();
    ~SportsCar() {
        cout << "SportsCar Destructor called\n" << endl;
    }
};

SportsCar::SportsCar(string make, string model, int year, int spd) 
    : Car(make, model, year), topspeed(spd){
    cout << "SportsCar Constructor called\n" << endl;
}

void SportsCar::drive() {
    cout<< "Drive a " << year << " " << make << " " << model << "with topspeed: " << topspeed << endl;
}

void some(Car* ptr) {
        ptr -> drive();
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

    //smart pointer
    unique_ptr<Car> ptr1(new Car("Hyundai", "Sonata", 2023));
    some(ptr1.get());
    
    unique_ptr<Car> ptr2 = move(ptr1);
    ptr2 -> drive();
    //memory is released automatically when ptr2 goes out of scope
    
    auto ptr3 = make_shared<SportsCar>("Ferrari", "488", 2022, 380);
    cout << ptr3.use_count() << endl; 

    auto ptr4(ptr3);
    cout << ptr3.use_count() << endl;

    auto ptr5(ptr3);
    cout << ptr3.use_count() << endl;
    
    return 0;
}
