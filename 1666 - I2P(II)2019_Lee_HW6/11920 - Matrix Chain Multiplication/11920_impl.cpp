#include <iostream>
#include "11920.h"
using namespace std;
Matrix Matrix::operator*(const Matrix &a) const
{
    //sigma(A[r][k] * B[k][c]) = C[r][c]
    Matrix c(size_row, a.get_size_col());
    int val=0;
    for (int i=0; i<this->size_row; i++) {
        for (int j=0; j<a.get_size_col(); j++) {
            for (int k=0; k<this->size_col; k++) {
                val += this->get_value(i, k) * a.get_value(k, j);
            }
            c.set_value(i, j, val);
            val = 0;
        }
    }
    return c;
}
Matrix Matrix::operator=(const Matrix &a)
{
    Matrix(a.get_size_row(), a.get_size_col());
    for (int i=0; i<a.get_size_row(); i++) {
        for (int j=0; j<a.get_size_col(); j++) {
            this->set_value(i, j, a.get_value(i, j));
        }
    }
    return *this;
}
Matrix MatrixChain::calc(int l, int r) const
{
    if (l==r-1) {
        return (*arr[l]);
    }
    return calc(l, r-1) * (*arr[r-1]);
}
