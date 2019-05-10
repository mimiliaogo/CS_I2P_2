#include <iostream>       // std::cerr
#include <sstream>        // std::stringstream
#include <stdexcept>      // std::out_of_range
#include <string>         // std::string
#include "Array.h"

using namespace std;
using namespace I2P2017;

Array::Array()      // default constructor
{
    size = 0;
    data = nullptr;
}

Array::Array( int n)  // constructor with size
{
    data = nullptr;
    setSize(n);
}

Array:: ~Array()                 // destructor
{
   delete [] data;
   data = nullptr;
   cout << "Array destructor is called\n";
}

// return the size of the array
int Array::getSize() const
{
    return size;
}

// set the size of the array
void Array::setSize(int n)
{
    if (data == nullptr) {
    // can only set size if data is NULL
        if(n>0) {
            size = n;
            data = new int[n];
      } else // throw error messages
            throw "Size should be >0.";

    } else    // throw error messages
        throw "Array has been initialized.";
}

// return the data at array[i]
int Array::getElementAt(int i) const {

    if (data == nullptr)
        // throw error messages
        throw "Array has not been initialized.";

    if (i<size && i>=0)
        return data[i];
    else {
        throw std::out_of_range("Out of range");
    }
}

// set the data at array[i]
void Array::setElementAt(int i, int value){

    if (data == nullptr)
        // throw error messages
        throw "Array has not been initialized.";

    if (i<size && i>=0)
        data[i] = value;
    else {
        throw std::out_of_range("Index out of range");
    }
}

// print the data of Array
void Array::print() const{

    std::cout << "Array size= "<< size << endl;
    for (int i=0; i<size; i++)
        std::cout << data[i] << " ";
    std::cout << endl;
}
/* ---------------------------------------------
    The implementation of Vector

-----------------------------------------------*/

Vector::Vector(): Array()
{
   capacity = 0;
} // end Vector constructor

Vector::Vector(const int size): Array(3*size)
{
   this->size = size;
   capacity = 3*size;
} // end Vector constructor

Vector:: ~Vector()                 // destructor
{
   delete [] data;
   data = nullptr;
   size = capacity = 0;
   cout << "Vector destructor is called\n";

}

// set the size of the array
void Vector::setSize(int n)
{
    if(capacity >= n)
        size = n;
    else {
        int *temp = data;
        data = new int(3*n);
        for (int i = 0; i< size; i++){
            data[i] = temp[i];
        }
        delete [] temp;
        size = n;
        capacity = 3*n;
    }
}

// set the size of the array
int Vector::getCapacity() const
{
    return capacity;
}


// print the Vector
void Vector::print() const
{

    std::cout << "Vector capacity = " <<capacity << ", ";
    Array::print();

}
