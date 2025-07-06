#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

//abstraction, inheritance, polymorphism, smart pointer 

class Part {//Abstraction: Part doen't know how each part is printed.
public:
    virtual void print() = 0;  //no implementation of context. just  a placeholder
};

class Engine : public Part{
private:
public:
    void print() {
        cout << "Engine Part\n";
    }
};

class Wheel : public Part {
public:
    void print() {
        cout << "Wheel Part\n" << endl;
    }
};

class Brake : public Part{
public:
    void print() {
        cout << "Brake Part\n" << endl;
    }
};

class Transmission : public Part{
public:
    void print() {
        cout << "Transmission Part\n" << endl;
    }
};

class Spoiler : public Part {
public:
    void print() {
        cout << "Spoiler Part\n";
    }
};

class Car {
protected:
    string name;
    string maker;
    int year;
    vector<unique_ptr<Part>> parts_;  //smart porinter
public:
    // //setter
    // void set(string name, string maker, int year) {
    //     this->name = name;
    //     this->maker = maker;
    //     this->year = year;
    // }

    Car(string name, string maker, int year) 
        : name(name), maker(maker), year(year) {//default constructor
        parts_.push_back(make_unique<Engine>());
        for (int i = 0; i < 4; i++) {
            parts_.push_back(make_unique<Wheel>());
        }
        for (int i = 0; i < 4; i++) {
            parts_.push_back(make_unique<Brake>());
        }
        parts_.push_back(make_unique<Transmission>());
        cout << "Car Constructor called\n" << endl;
    }

    //Car(const Car& obj) {}; //copy consturctor
    
    //Car& operator=(const Car& obj) {}; 
    
    virtual ~Car() {
        cout << this->name << " destroyed.\n" << endl;
    };

    void printParts() {
        for (const auto& part : parts_) {
            part->print();  //important - polymorphism
        }
    }
};

class SportsCar : public Car {
private:
    int topSpeed;
public:
    // //setter
    // void settopSpeed(int topSpeed) {this->topSpeed = topSpeed;}
    SportsCar(string name, string maker, int year, int topSpeed)
        : Car(name, maker, year), topSpeed(topSpeed) {
        parts_.push_back(make_unique<Spoiler>());
    }
};

// class F1Machine : public SportsCar {
// private:
//     int rpm;
// public:
//     //setter
//     void setrpm(int rpm) {this->rpm = rpm;}
// };

int main() {
    Car AudiA6("Audi A6", "Audi", 2023);
    AudiA6.printParts();  //print parts

    SportsCar AudiR8("Audi R8", "Audi", 2023, 300);
    AudiR8.printParts(); //print parts
}