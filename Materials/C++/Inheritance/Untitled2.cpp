#include <iostream>
using namespace std;
class A {
public:
    A() {
        cout<< "A's const" << endl;
    }
    ~A() {
        cout<< "A's dest" << endl;
    }
};
class B : public A{
public:
    B() {
        cout<< "B's const" << endl;
    }
    ~B() {
        cout<< "B's dest" << endl;
    }
};
class C : public B{
public:
    C() {
        cout<< "C's const" << endl;
    }
    ~C() {
        cout<< "C's dest" << endl;
    }
};
int main()
{
    C* test = new C;
    delete test;
    //see the order of calling
}
