#include <iostream>       // std::cerr
#include <sstream>        // std::stringstream
#include <stdexcept>      // std::out_of_range
#include <string>         // std::string
#include "Array.h"

using namespace std;
using namespace I2P2019;

Array::Array()      // default constructor
{
    size = 0;
    data = nullptr;
}

Array::Array( int n)  // constructor with size
{
    data = nullptr;
    setArraySize(n);

}

Array:: ~Array()                 // destructor
{
   delete [] data;
   data = nullptr;
}

// return the size of the array
int Array::getArraySize() const
{
    return size;
}

// set the size of the array
void Array::setArraySize(int n)
{
    if (data == nullptr) {
    // can only set size if data is NULL
        if(n>0) {
            size = n;
            data = new int[n];
      } else // throw error messages
            throw "Array size should be >0.";

    } else    // throw error messages
        throw "Array has been initialized.";
}

std::string errMsg(int i, int size){
        std::stringstream errorMessage;
        std::string err;
        errorMessage << "Index is out of Array size.";
        errorMessage >> err;
        return err;
}

// return the data at array[i]
int Array::getElementAt(int i) const {

    if (data == nullptr)
        // throw error messages
        throw "Array has not been initialized.";

    if (i<size && i>=0)
        return data[i];
    else {
        throw std::out_of_range(errMsg(i, size));
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
        throw std::out_of_range(errMsg(i, size));
    }
}


/* function that displays a welcome  message to the Array users*/
void Array::displayMessage() const
{
    std::cout<<"Using Array Class." << std::endl;
}
