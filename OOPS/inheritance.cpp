#include <iostream>
using namespace std;

class car {
protected:
  string brand;
  string model;
  bool isEngineOn;
  int currentSpeed;

public:
  car(string brand, string model) {
    this->brand = brand;
    this->model = model;
    isEngineOn = false;
    currentSpeed = 0;
  }

  // common methods for all cars
  void startEngine() {
    if (isEngineOn) {
      cout << "Car is already start" << endl;
      return;
    }
    isEngineOn = true;
    cout << "Car started" << endl;
  }

  void stopEngine() {
    if (!isEngineOn) {
      cout << "car is already stop" << endl;
      return;
    }
    isEngineOn = false;
    cout << "Car stopped" << endl;
  }

  void accelerate() {
    if (!isEngineOn) {
      cout << "Start the car first" << endl;
      return;
    }
    currentSpeed += 20;
    cout << "Car in running now at speed: " << currentSpeed << endl;
  }

  virtual void makeSound() { cout << "Generic Car Sound" << endl; }
};

class manualCar : public car {
private:
  int currentGear;

public:
  manualCar(string b, string m) : car(b, m) { currentGear = 0; }

  void shiftGear(int gear) {
    currentGear = gear;
    cout << brand << " " << model << " " << " : shifted to " << currentGear
         << endl;
  }

  void makeSound() override {
    cout << "Manual Car Sound: Vroom Vroom!" << endl;
  }
};

class electricCar : public car {
private:
  int battery;

public:
  electricCar(string b, string m) : car(b, m) { battery = 0; }

  void charge() {
    if (battery == 100) {
      cout << "Battery is already full" << endl;
      return;
    }
    battery += 10;
    if (battery > 100)
      battery = 100;
    cout << "Battery Percentage is " << battery << endl;
  }
};

int main() {
  manualCar *mycar = new manualCar("AUDI", "B6");
  mycar->startEngine();
  mycar->shiftGear(4);
  mycar->accelerate();

  // Demonstration of Virtual Functions
  car *basePtr = mycar;
  cout << "Calling makeSound using base class pointer:" << endl;
  basePtr->makeSound();
}