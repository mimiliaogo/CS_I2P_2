#include <iostream>       // std::cerr
#include <sstream>        // std::stringstream
#include <stdexcept>      // std::out_of_range
#include <string>         // std::string
using namespace std;

namespace I2P {

    // class definition
    template <class CType>
    class Array{
    private:
        int size;   // size of the array
        CType *data;  // data of the array

    public:

       Array();                 // default constructor
       explicit Array( int n);  // constructor with size
       ~Array();                // destructor

       // return the size of the array
       int getArraySize() const;
       // set the size of the array
       void setArraySize(int);

       // return the data at array[i]
       CType getElementAt(int) const;
       // set the data at array[i]
       void setElementAt(int, CType);

    }; // end class Array


    template<class CType>
    Array<CType>::Array()      // default constructor
    {
        size = 0;
        data = nullptr;
    }

    template<class CType>
    Array<CType>::Array(int n)  // constructor with size
    {
        data = nullptr;
        setArraySize(n);

    }

    template<class CType>
    Array<CType>::~Array()                 // destructor
    {
       delete [] data;
       data = nullptr;
    }

    // return the size of the array
    template<class CType>
    int Array<CType>::getArraySize() const
    {
        return size;
    }

    // set the size of the array
    template<class CType>
    void Array<CType>::setArraySize(int n)
    {
        if (data == nullptr) {
        // can only set size if data is NULL
            if(n>0) {
                size = n;
                data = new CType[n];
          } else // throw error messages
                throw "Array size should be >0.";

        } else    // throw error messages
            throw "Array has been initialized.";
    }

    // return the data at array[i]
    template<class CType>
    CType Array<CType>::getElementAt(int i) const {

        if (data == nullptr)
            // throw error messages
            throw "Array has not been initialized.";

        if (i<size && i>=0)
            return data[i];
        else {
            throw std::out_of_range("Out of range\n");
        }
    }

    // set the data at array[i]
    template<class CType>
    void Array<CType>::setElementAt(int i, CType value){

        if (data == nullptr)
            // throw error messages
            throw "Array has not been initialized.";

        if (i<size && i>=0)
            data[i] = value;
        else {
            throw std::out_of_range("Out of Range\n");
        }
    }
}
