
namespace I2P2019 {

    // class definition
    class Array{
    private:
        int size;   // size of the array
        int *data;  // data of the array

    public:

       Array();                 // default constructor
       explicit Array( int n);  // constructor with size
       ~Array();                // destructor

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

    }; // end class Array

}
