#include <iostream>
#include "function.h"
using namespace std;
Animal::Animal(Zoo *zoo, string name) {
    belong = zoo;
    species = name;
    belong->born(name);
}
Dog::Dog(Zoo* zoo):Animal(zoo, "Dog"){}
Cat::Cat(Zoo* zoo):Animal(zoo, "Cat"){}
Caog::Caog(Zoo* zoo): Dog(zoo), Cat(zoo), Animal(zoo, "Caog"){}
Dog::~Dog() {
    ;
}
Cat::~Cat() {
    ;
}
Caog::~Caog() {
    ;
}
void Caog::barking() {
    cout<<"woof!woof!meow!"<<endl;
}
void Caog::carton()
{
    Cat::carton();
}        // TODO
void Caog::throwBall()
{
    Dog::throwBall();
}     // TODO
