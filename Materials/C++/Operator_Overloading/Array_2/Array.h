#include <iostream>

using namespace std;

namespace I2P2019 {

    // class definition
    class Array{
    private:
        int size;   // size of the array
        int *data;  // data of the array
        static unsigned int serial_num;  //serial number
        int id;     // id of the matrix


    public:

        Array();                 // default constructor
        explicit Array(int n);   // constructor with size
        Array(const Array& B);   // copy constructor

        ~Array();                // destructor

        //static member function
        static unsigned int getSN(){
            return Array::serial_num;
        } // return # of objects instantiated

       // return the size of the array
       int getArraySize() const;
       // set the size of the array
       void setArraySize(int);

       // return the data at array[i]
       int getElementAt(int) const;
       // set the data at array[i]
       void setElementAt(int, int);

       /* function that displays a welcome  message to the Array users*/
       void displayMessage() const;

       // operator overloading
       /* binary operators*/
       Array operator+ (const Array&) const;

       /* unitary operators*/
       Array operator-() const;

       /* for ++ operators that has prefix and postfix usage.*/
       Array &operator++();    // prefix increment operator
       Array operator++(int);  // postfix increment operator

       /* assignment */
       const Array &operator=( const Array & );

       /* element at */
       int operator [] (int) const;        // right hand side
       int& operator[] (int);              // left hand side

       /* friend input and output stream operator << >> */
       friend ostream& operator<<(ostream &output, const Array&);
       friend istream& operator>>(istream &input, Array&);

    }; // end class Array
}
