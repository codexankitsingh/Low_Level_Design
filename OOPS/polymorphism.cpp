#include <iostream>
using namespace std;

// 1.Dynamic Polymorphism (method overriding)
// 2. static Polymorphism (method overloading)

class car
{
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

public:
    car(string brand, string model)
    {
        this->brand = brand;
        this->model = model;
        isEngineOn = false;
        currentSpeed = 0;
    }

    // common methods for all cars
    void startEngine()
    {
        if (isEngineOn)
        {
            cout << "Car is already start" << endl;
            return;
        }
        isEngineOn = true;
        cout<<brand<<" "<<model<<" started" << endl;
    }

    void stopEngine()
    {
        if (!isEngineOn)
        {
            cout << "car is already stop" << endl;
            return;
        }
        isEngineOn = false;
        cout << "Car stopped" << endl;
    }

    virtual void accelerate() = 0;
    virtual void brake() = 0;
};

class manualCar : public car
{
private:
    int currentGear;

public:
    manualCar(string b, string m) : car(b, m) { currentGear = 0; }

    void shiftGear(int gear)
    {
        currentGear = gear;
        cout << brand << " " << model << " " << " : shifted to " << currentGear
             << endl;
    }

    void accelerate()
    {
        if (!isEngineOn)
        {
            cout << "First Start the car " << endl;
            return;
        }
        currentSpeed += 20;
        cout << "car speed to now " << currentSpeed << endl;
    }

    void brake()
    {
        currentSpeed -= 10;
        if (currentSpeed < 0)
            currentSpeed = 0;
        cout << "Brake applied, speed is now " << currentSpeed << endl;
    }
};

class electricCar : public car
{
private:
    int battery;

public:
    electricCar(string b, string m) : car(b, m) { battery = 0; }

    void charge()
    {
        if (battery == 100)
        {
            cout << "Battery is already full" << endl;
            return;
        }
        battery += 10;
        if (battery > 100)
            battery = 100;
        cout << "Battery Percentage is " << battery << endl;
    }

    void accelerate()
    {
        if (!isEngineOn)
        {
            cout << "First Start the car " << endl;
            return;
        }
        currentSpeed += 10;
        cout << "car speed to now " << currentSpeed << endl;
    }

    void brake()
    {
        currentSpeed -= 5;
        if (currentSpeed < 0)
            currentSpeed = 0;
        cout << "Brake applied, speed is now " << currentSpeed << endl;
    }
};

int main()
{
    manualCar *mycar = new manualCar("AUDI", "B6");
    mycar->startEngine();
    mycar->shiftGear(4);
    mycar->accelerate();
    mycar->brake();
    cout<<"-------------------------------------"<<endl;

    electricCar* tesla = new electricCar("Tesla","musk7");
    tesla->startEngine();
    tesla->charge();
    tesla->accelerate();
    tesla->brake();
}

/*
A class with pure virtual functions is called an Abstract Class, meaning you
cannot create objects of it directly. Any derived class (like manualCar ) must
provide implementations for all pure virtual functions to become a concrete
(instantiable) class.

Currently, your manualCar class sorts out accelerate(), but it fails to implement brake(). As a result,manualCar is still considered an abstract class, and the compiler prevents you from creating a new manualCar at line 99.

To fix this, we need to implement the brake() function in the manualCarclass.
*/