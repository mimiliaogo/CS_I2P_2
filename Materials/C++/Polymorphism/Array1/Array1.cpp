#include <iostream>       // std::cerr
#include <sstream>        // std::stringstream
#include <stdexcept>      // std::out_of_range
#include <string>         // std::string
#include "Array1.h"

using namespace std;
using namespace I2P2017;

ContinuousList::ContinuousList()      // default constructor
{
    size = 0;
    data = nullptr;
    cout << "CL default constructor\n";
}

ContinuousList::ContinuousList( int n)  // constructor with size
{
    data = nullptr;
    cout << "CL constructor\n";
}

ContinuousList:: ~ContinuousList()                 // destructor
{
   delete [] data;
   data = nullptr;
   cout << "CL destructor\n";
}

// return the size of the array
int ContinuousList::getSize() const
{
    return size;
}

// return the data at array[i]
int ContinuousList::getElementAt(int i) const {

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
void ContinuousList::setElementAt(int i, int value){

    if (data == nullptr)
        // throw error messages
        throw "Array has not been initialized.";

    if (i<size && i>=0)
        data[i] = value;
    else {
        throw std::out_of_range("Index out of range");
    }
}

// print the data of ContinuousList
void ContinuousList::print() const{

    for (int i=0; i<size; i++)
        std::cout << data[i] << " ";
    std::cout << endl;
}



/* ---------------------------------------------
    The implementation of Array
-----------------------------------------------*/

Array::Array(){
    cout << "Array default constructor\n";
} // end Array constructor

Array::Array(const int size){
    setSize(size);
    cout << "Array constructor\n";

} // end Array constructor

Array:: ~Array()   {
    cout << "Array destructor\n";
} // destructor

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

// print the data of Array
void Array::print() const{

    std::cout << "Array size= "<< size << endl;
    ContinuousList::print();
}

/* ---------------------------------------------
    The implementation of Vector
-----------------------------------------------*/

Vector::Vector()
{
   capacity = 0;
   cout << "Vector default constructor\n";

} // end Vector constructor

Vector::Vector(const int size)
{
   this->size = size;
   capacity = 3*size;
   data = new int[capacity];
   cout << "Vector constructor\n";

} // end Vector constructor

Vector:: ~Vector()                 // destructor
{
   cout << "Vector destructor\n";
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
    ContinuousList::print();

}
