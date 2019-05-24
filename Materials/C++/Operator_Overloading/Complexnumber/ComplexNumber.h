#include <iostream>

using namespace std;
class complex {
private:
   double r;
   double i;

public:
   complex(){r = i = 0;} // default constructor
   complex(double r, double i):r(r),i(i){}
   complex(const complex& c) { //copy constructor
       r = c.r; i = c.i;
   }

   /* Two ways to define binary operators*/
   /* 1. a non-static member function with 1 argument.*///since itself can use "this" to access
   complex operator+ (const complex&);
   /* 2. a non-member function with 2 arguments.*/
   friend complex operator*(const complex&, const complex&);

   /* Two ways to define unitary operators*/
   /* 1. a non-static member function with 0 argument.*/
   complex operator-();
   /* 2. a non-member function with 1 arguments.*/
   friend complex operator~(const complex&);

   /* for ++ operators that has prefix and postfix usage.*/
   complex &operator++();  // prefix increment operator
   complex operator++(int);  // postfix increment operator

   /* input and output stream operator << >> */
   friend ostream& operator<< (ostream &output, const complex& c);
   friend istream& operator>> (istream &input, complex& c);
};
