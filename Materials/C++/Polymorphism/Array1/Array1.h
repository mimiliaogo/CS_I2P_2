
namespace I2P2017 {

    // class definition
    class ContinuousList{
    protected:
        int size;   // size of the array
        int *data;  // data of the array

    public:

        ContinuousList();                 // default constructor
        ContinuousList(const int n);  // constructor with size
        virtual ~ContinuousList();        // destructor

        // return the size of the array
        int getSize() const;
        // pure virtual function: set the size of the array
        virtual void setSize(int)=0;

        // return the data at array[i]
        int getElementAt(int) const;
        // set the data at array[i]
        void setElementAt(int, int);

        virtual void print() const;

    }; // end class Array


    // class definition
    class Array: public ContinuousList {

    public:

        Array();        // default constructor
        Array(const int n);   // constructor with size
        ~Array();       // destructor

        // set the size of the vector
        virtual void setSize(int) override;

        // print out the vector
        virtual void print() const override;

    }; // end class Array

    // class definition
    class Vector: public ContinuousList {
    private:
        int capacity;   // size of the vector storage

    public:

        Vector();        // default constructor
        Vector(const int n);   // constructor with size
        ~Vector();       // destructor

        // get the capacity of the vector
        int  getCapacity() const;

        // set the size of the vector
        virtual void setSize(int) override;

        // print out the vector
        virtual void print() const override;

    }; // end class Vector

}
