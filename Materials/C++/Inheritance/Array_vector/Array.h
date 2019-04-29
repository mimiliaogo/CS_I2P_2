
namespace I2P2017 {

    // class definition
    class Array{
    protected:
        int size;   // size of the array
        int *data;  // data of the array

    public:

        Array();                 // default constructor
        explicit Array(const int n);  // constructor with size
        ~Array();                // destructor

        // return the size of the array
        int getSize() const;
        // set the size of the array
        void setSize(int);

        // return the data at array[i]
        int getElementAt(int) const;
        // set the data at array[i]
        void setElementAt(int, int);

        void print() const;

    }; // end class Array


    // class definition
    class Vector: public Array {
    private:
        int capacity;   // size of the vector storage

    public:

        Vector();        // default constructor
        Vector(const int n);   // constructor with size
        ~Vector();       // destructor

        // get the capacity of the vector
        int  getCapacity() const;

        // set the size of the vector
        void setSize(int);

        // print out the vector
        void print() const;

    }; // end class Vector

}
