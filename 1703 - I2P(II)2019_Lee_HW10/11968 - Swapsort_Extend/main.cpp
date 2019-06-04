#include "function.hpp"

int main()
{
    State s;// = {2, 1, 3};
    int e;
    while (cin >> e) { // press Ctrl + Z to end the input
        s.push_back(e);
    }
    SwapSort prob1(s);
    prob1.solve(4);
    prob1.show_solutions();
    cout << "\n";
}
