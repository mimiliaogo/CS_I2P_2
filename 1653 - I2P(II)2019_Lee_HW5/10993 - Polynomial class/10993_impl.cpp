#include <iostream>
#include "10993.h"
using namespace std;


Polynomial::Polynomial()
{
    for (int i=0; i<51; i++) {
        coefficients[i] = 0;
    }
    greatestPower = 0;
}
Polynomial::Polynomial(const int GPow, const int co[51]) {
   for (int i=0; i<51; i++) {
        coefficients[i] = 0;
    }
    for (int i=0; i<=GPow; i++) {
        coefficients[i] = co[i];
    }
    greatestPower = GPow;
}
Polynomial Polynomial::add( const Polynomial p2) const{
    Polynomial padd;
    if (greatestPower<p2.greatestPower) padd.greatestPower = p2.greatestPower;
    else padd.greatestPower = greatestPower;
    for (int i=0; i<=padd.greatestPower; i++) {
        padd.coefficients[i]=coefficients[i]+p2.coefficients[i];
    }
    return padd;
}
Polynomial Polynomial::subtract(const Polynomial p2) const{
    Polynomial psub;
    if (greatestPower<p2.greatestPower) psub.greatestPower = p2.greatestPower;
    else psub.greatestPower = greatestPower;
    for (int i=0; i<=psub.greatestPower; i++) {
        psub.coefficients[i]=coefficients[i]-p2.coefficients[i];
    }
    while (psub.coefficients[psub.greatestPower]==0) psub.greatestPower--;

    return psub;
}
Polynomial Polynomial::multiplication(const Polynomial p2) const {
    Polynomial pmul;
    pmul.greatestPower =greatestPower +p2.greatestPower;
    for (int i=0; i<=p2.greatestPower; i++) {
        for (int j=0; j<=greatestPower; j++) {
            pmul.coefficients[i+j] += coefficients[j]*p2.coefficients[i];
        }
    }
    return pmul;
}

void Polynomial::output() const
{
    for (int i=greatestPower; i>0; i--) {
        cout<<coefficients[i]<<" ";
    }
    cout<<coefficients[0];
}
