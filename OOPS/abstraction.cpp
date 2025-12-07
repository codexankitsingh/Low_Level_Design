#include <iostream>
using namespace std;

class car { // abstract class
public:
  virtual void startEngine() = 0;
  virtual void siftgear(int gear) = 0;
  virtual void brake() = 0;
  virtual void accelerate() = 0;
  virtual void stopengine() = 0;

  virtual ~car() {}; // destructor of car
};

class SportsCar : public car {
public:
  string brand;
  string model;
  bool isEngineOn;
  int currentGear;
  int currentSpeed;

  SportsCar(string b, string m) {
    this->brand = b;
    this->model = m;
    isEngineOn = false;
    currentGear = 0;
    currentSpeed = 0;
  }

  void startEngine() {
    isEngineOn = true;
    cout << "Engine started" << endl;
    return;
  }

  void siftgear(int gear) {
    if (!isEngineOn) {
      cout << "Please start the engine first" << endl;
      return;
    }
    if (gear < 1 && gear > 6) {
      cout << "Invalid Gear value" << endl;
      return;
    }
    currentGear = gear;
    cout << "Gear sifted to " << currentGear << endl;
    return;
  }

  void accelerate() {
    if (!isEngineOn) {
      cout << "Please start the engine first" << endl;
      return;
    }
    currentSpeed += 20;
    cout << "Car is now Accelerating at a speed of : " << currentSpeed << "km/h"
         << endl;
    return;
  }

  void brake() {
    if (!isEngineOn) {
      cout << "Please start the engine first" << endl;
      return;
    }
    currentSpeed -= 20;
    cout << "Car is now braking at a speed of : " << currentSpeed << "km/h"
         << endl;
    return;
  }

  void stopengine() {
    if (!isEngineOn) {
      cout << "Please start the engine first" << endl;
      return;
    }
    isEngineOn = false;
    cout << "Engine stopped" << endl;
    return;
  }
};

int main() {
  car *mycar = new SportsCar(
      "BMW", "M4"); // pointer of base class pointing to object of derived class
  mycar->startEngine();
  mycar->siftgear(4);
  mycar->accelerate();
  mycar->accelerate();
  mycar->brake();
  mycar->stopengine();
  delete mycar;
  return 0;
}