#include <iostream>
#include "function.h"
using namespace std;
Matrix Matrix::operator*(const Matrix &a) const
{
    int val=0;
    Matrix mat(size_row, a.get_size_col());
    for (int i=0; i<size_row; i++) {
        for (int j=0; j<a.get_size_col(); j++) {
            for (int k=0; k<size_col; k++) {
                val += arr[i][k]*a.get_value(k, j);
            }
            mat.set_value(i, j, val);
            val = 0;
        }
    }
    return mat;
}
Matrix Matrix::operator=(const Matrix &a)
{
    this->size_col = a.get_size_col();
    this->size_row = a.get_size_row();
    for (int i=0; i<size_row; i++) {
        for (int j=0; j<size_col; j++) {
            this->arr[i][j] = a.get_value(i, j);
        }
    }
    return *this;
}
Matrix MatrixChain::calc(int l, int r) const
{
    if (l>=r-1) return *arr[l];
    else return calc(l, r-1)*(*arr[r-1]);
}
