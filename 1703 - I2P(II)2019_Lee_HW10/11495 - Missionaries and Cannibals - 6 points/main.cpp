#include <iostream>
#include <fstream>
#include "function.h"

using namespace std;

int main(int argc, char *argv[]) {
    int X, Y; //Number of missionaries and cannibals
    cin >> X >> Y;
    Crossing p({X, Y});
    p.solve();
    p.show_solutions();
}