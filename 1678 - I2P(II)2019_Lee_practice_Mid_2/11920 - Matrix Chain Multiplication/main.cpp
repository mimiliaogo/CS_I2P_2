#include "function.h"
#include <iostream>
using namespace std;

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
  int r = m.get_size_row();
  int c = m.get_size_col();
  for (int i = 0; i < r; i++) {
    int* tmp = m.get_row(i);
    for (int j = 0; j < c; j++) {
      os << tmp[j] << " ";
    }
    os << "\n";
  }
  return os;
}

int main() {
  int Mat_num, row, col, val;
  cin >> Mat_num;
  MatrixChain MCChen(Mat_num);
  for (int i = 0; i < Mat_num; i++) {
    cin >> row >> col;
    Matrix* now = MCChen.setMatrix(i, row, col);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        cin >> val;
        now->set_value(i, j, val);
      }
    }
  }
  int l, r;
  cin >> l >> r;
  Matrix m(MCChen.arr[l]->get_size_row(), MCChen.arr[r - 1]->get_size_col());
  m = MCChen.calc(l, r);
  cout << m;
}
