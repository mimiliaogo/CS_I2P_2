#include <iostream>
#include "ComplexNumber.h"

using namespace std;

complex complex::operator+(const complex & c){
    return complex(c.r + this->r, c.i + this->i);// each return use copy constructor
}

complex operator*(const complex& a, const complex& b){
    return complex (a.r*b.r-a.i*b.i, a.r*b.i+a.i*b.r);
}

istream& operator>> (istream &input, complex& c){
   char p;
   char i;
   input >> c.r >> p >> c.i >> i;
   return input;
}

ostream& operator<< (ostream &output, const complex& c){
    if (c.i>=0)
        output << "(" << c.r << "+" << c.i << "i)";
    else
        output << "(" << c.r << c.i << "i)";
   return output;
}

/*negative of complex.*/
complex complex::operator-(){
    return complex(-this->r, -this->i);
}

/* conjugate of complex*/
complex operator~(const complex& c){
    return complex (c.r, -c.i);
}

complex& complex::operator++()  // prefix increment operator
{
    r++; i++;
    return *this;//:dereference and use reference to return
}
complex complex::operator++(int)  // postfix increment operator
{
    complex c = *this;
    r++; i++;
    return c;
}
