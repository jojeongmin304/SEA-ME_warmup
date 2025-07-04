#include <iostream>

using namespace std;

class Car {
private:
    string name;
    int speed;
public:
    Car();
    Car(const Car& obj);
    Car& operator=(const Car& obj);
    ~Car();
};

Car::Car() {
    this->name = "Default Car";
    this->speed = 0;
    cout << "Car Constructor Created\n";
}
// Car::Car() : name("Default Car"), speed(0) {
//     cout << "Car Consturctor Created\n";
// }

Car::Car(const Car& obj) {
    *this = obj;
    cout << "Car Constructor Copy Created\n";
}
// Car::Car(const Car& obj) : name(obj.name), speed(obj.speed)  {
//     cout << "Car Constructor Copy Created\n";
// }

Car& Car::operator=(Car const& obj) {  // Copy Assignment operator overload (with copy constructor)
    if (this != &obj) {
        this->name = obj.name;
        this->speed = obj.speed;
    }
}

Car::~Car() {
    cout << "Car Destructor Called\n";
    // No need to delete heap memory as we are not using any dynamic memory allocation
    // If we had used dynamic memory allocation, we would need to delete it here.
}

int main() {
    Car car1; //Default consturctor
    Car car2(car1); // Copy constructor
    Car car3;
    car3 = car1; // Copy assignment operator overlead

    return 0;
}