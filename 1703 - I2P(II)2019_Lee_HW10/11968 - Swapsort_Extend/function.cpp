#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include "function.hpp"
using namespace std;
set<State> SwapSort::extend(State s)
{
    set <State> ss;
    State last, second;
    last = s;
    second = s;

    swap(last[0], last[s.size()-1]);
    swap(second[0],second[1]);
    ss.insert(last);
    ss.insert(second);

    return ss;
}

