#include <iostream>
using namespace std;
class Zoo {
public:
  int animalCount;
  Zoo() { animalCount = 0; }
  void born(string name) {
    animalCount += 1;
    cout << "New " << name << " Born!\n";
    cnt();
  }
  void dead(string name) {
    animalCount -= 1;
    cout << "One " + name + " Dead!\n";
    cnt();
  }
  void cnt() { cout << "Now Zoo have " << (animalCount) << " animals!\n"; }
};
class Animal {
public:
  Zoo *belong;
  string species;
  int legs;
  Animal(Zoo *zoo, string name); // TODO
  virtual void barking() = 0;
  virtual void throwBall() = 0;
  virtual void carton() = 0;
  void printSpecies() { cout << this->species << "\n"; }
  virtual ~Animal() {
    if (this->belong != NULL)
      this->belong->dead(this->species);
  }; // Please Ensure that you know what this destructure is.
};
class Dog : public virtual Animal {
public:
  Dog(Zoo *zoo); // TODO
  void barking() { cout << "woof!\n"; }
  void throwBall() { cout << "it looks happy!\n"; }
  virtual void carton(){};
  ~Dog(); // TODO
};
class Cat : public virtual Animal {
public:
  Cat(Zoo *zoo); // TODO
  void barking() { cout << "meow!\n"; }
  void carton() { cout << "it looks so happy!\n"; }
  virtual void throwBall(){};
  ~Cat(); // TODO
};
class Caog : public Dog, public Cat {
public:
  Caog(Zoo *zoo);         // TODO
  virtual void barking(); // TODO
  void carton();          // TODO
  void throwBall();       // TODO
  ~Caog();                // TODO
};