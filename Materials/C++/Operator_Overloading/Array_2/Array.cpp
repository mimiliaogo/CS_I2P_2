#include <iostream>       // std::cerr
#include <sstream>        // std::stringstream
#include <stdexcept>      // std::out_of_range
#include <string>         // std::string
#include "Array.h"

using namespace std;
using namespace I2P2019;

unsigned int I2P2019::Array::serial_num = 0;

Array::Array()      // default constructor
{
    size = 0;
    data = nullptr;
    id = Array::serial_num++;
}

Array::Array( int n)  // constructor with size
{
    data = nullptr;
    setArraySize(n);
    id = Array::serial_num++;
}

Array::Array(const Array& B)   // copy constructor
{
    data = nullptr;
    try{
        setArraySize(B.size);
        for (int i=0; i<size; i++)
            data[i] = B.data[i];

    } catch(const char* errmsg) {  // forward the error message to the caller
        throw errmsg;
    }
    id = Array::serial_num++;
    cout << id <<endl;
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
            for (int i=0; i<n; i++)   // initialize the data
                data[i] = 0;

      } else // throw error messages
            throw "Array size should be >0.";

    } else    // throw error messages
        throw "Array has been initialized.";
}

std::string errMsg(int i, int size){
    std::stringstream errorMessage;
    std::string err;
    errorMessage << "Index " << i << " is out of Array size [0," << size-1 <<"].";
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

// overloaded operator +;
// return C = A + B
Array Array::operator+( const Array &B ) const
{
   if ( size != B.size )
    throw "arrays of different number of elements\n"; // arrays of different number of elements

   Array C(B);

   for ( int i = 0; i < size; ++i )
      C.data[i] += data[i];

   return C;
} // end function operator+

// overloaded operator -;
// return C = -A
Array Array::operator-() const
{
    Array C(*this);
    for ( int i = 0; i < size; ++i )
        C.data[i] = -data[i];

    return C;
} // end function operator-


// overloaded assignment operator;
// const return avoids: ( a1 = a2 ) = a3
const Array &Array::operator=( const Array &B)
{
    if (size == B.size) {
        if ( &B != this ){ // avoid self-assignment
            for (int i=0; i<size; i++)
                data[i] = B.data[i];
        } else  // self copy
            throw "cannot self copy \n";

    } else if (data == nullptr) { // copy assignment constructor
           try{
                setArraySize(B.size);
                for (int i=0; i<size; i++)
                    data[i] = B.data[i];
            } catch(const char* errmsg) {  // forward the error message to the caller
                throw errmsg;
            }
    }
    return *this; // enables x = y = z, for example
} // end function operator=

// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
int Array::operator[]( int i) const
{
   return getElementAt(i); // returns copy of this element
} // end function operator[]

// overloaded subscript operator for non-const Arrays;
// reference return creates a modifiable lvalue
int &Array::operator[]( int i)
{
   // check for subscript out-of-range error
   if ( i< 0 || i >= size )
      throw out_of_range( "Subscript out of range" );

   return data[i]; // reference return//since in the lhs like scanf &
} // end function operator[]


// overload prefix increment operator  ++A
Array& Array::operator++() {
    for ( int i = 0; i < size; ++i )
        data[i]++;

    return *this;
}

// overload postfix increment operator A++
Array Array::operator++(int dummy) {

    Array C = *this;
    for ( int i = 0; i < size; ++i )
        data[i]++;

    return C;
}

namespace I2P2019 {
    // overloaded input operator for class Array;
    // inputs values for entire Array
    istream& operator>>(istream &input, Array &A )
    {
        int i;
        for ( i = 0; i < A.size; ++i )
          input >> A.data[i];

       return input; // enables cin >> x >> y;
    } // end function

    // overloaded output operator for class Array
    ostream& operator<<(ostream &output, const Array& A)
    {
       // output private ptr-based array
       int i;
       output << "Array " << A.id << ": ";
       for (i = 0; i < A.size; ++i ) {
          output << " " << A.data[i];
       }

       return output; // enables cout << x << y;
    } // end function operator<<
}
