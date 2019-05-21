#include <iostream>       // std::cerr
#include <sstream>        // std::stringstream
#include <stdexcept>      // std::out_of_range
#include <string>         // std::string
using namespace std;

namespace I2P {

    // class definition
    template <class CType, int n>
    class Array{
    private:
        int size;   // size of the array
        CType *data;  // data of the array

    public:
       typedef int Iterator;

       Array();                 // default constructor
       ~Array();                // destructor

       // return the size of the array
       int getArraySize() const;

       // return the data at array[i]
       CType getElementAt(int) const;
       // set the data at array[i]
       void setElementAt(int, CType);

       Iterator begin(){
          return 0;
       }

       Iterator end(){
          return size;
       }

    }; // end class Array

    template<class CType, int n>
    Array<CType,n>::Array()      // default constructor
    {
        data = new CType[n];
        size = n;
    }

    template<class CType, int n>
    Array<CType,n>::~Array()                 // destructor
    {
       delete [] data;
       data = nullptr;
    }

    // return the size of the array
    template<class CType, int n>
    int Array<CType,n>::getArraySize() const
    {
        return size;
    }

    // return the data at array[i]
    template<class CType, int n>
    CType Array<CType,n>::getElementAt(int i) const {

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
    template<class CType, int n>
    void Array<CType,n>::setElementAt(int i, CType value){

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
