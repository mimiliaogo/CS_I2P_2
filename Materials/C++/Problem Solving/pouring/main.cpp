#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <list>
#include <iterator>
#include <string>
#include <sstream>

using namespace std;
using State = vector<int>;
class Pouring
{
private:
    vector<int> _capacities; // {3, 5}
    set<State> _explored;    // the states appeared before
    set<list<State>> _paths; // the paths
    set<list<State>> _solutions;

public:
    Pouring(vector<int> cp): _capacities{cp} { }
    State Empty(State s, int jug_no)
    {
        s[jug_no] = 0;
        return s;
    }
    State Fill(State s, int jug_no)
    {
        s[jug_no] = _capacities[jug_no];
        return s;
    }
    State Pour(State s, int from, int to)
    {
        State t = s;
        int diff = _capacities[to]-s[to];
        if (diff < s[from]) {
            t[to] = _capacities[to];
            t[from] = s[from]-diff;
        } else {
            t[from] = 0;
            t[to] = s[to] + s[from];
        }
        return t;
    }
    ///try 3 ways and generate all possible states
    /*For example
    (5, 0)--->
    empty:(0, 0)  (5, 0)
    fill: (5, 0)  (5, 3)
    pour: (0, 5)  (5, 0)
    */
    set<State> extend(State s)
    {
        set<State> SS;

        for (int i=0; i<_capacities.size(); ++i) {
            SS.insert(Empty(s, i));
            SS.insert(Fill(s, i));
            for (int j=0; j<_capacities.size(); ++j) {
                if (i!=j)
                    SS.insert(Pour(s, i, j));//0->1 or 1->0
            }
        }
        return SS;
    }

    void show_state(State s)
    {
        for (auto i : s)
            cout << i << ", " ;
        cout << "->";
    }
    bool found(State s, int target)
    {
        for (auto t : s) {
            if (t==target) return true;
        }
        return false;
    }

    void solve(int target, int steps)
    {
        list<State> initialPath;

        initialPath.push_back(State(_capacities.size()));
        //making a State with size 2
        //default state vector is (0, 0)
        _paths.insert(initialPath);

        while (steps > 0) {
            set<list<State>> newPaths;
            set<list<State>> oldPaths;

            for (auto p : _paths) {
                _explored.insert(p.back());
                auto nextStates = extend(p.back());
                for (auto s : nextStates) {
                    if (found(s, target)) {
                        auto np = p;
                        np.push_back(s);
                        _solutions.insert(np);
                        //a new solution path is made,
                        //and the search for that path is stopped
                    } else {
                        auto search = _explored.find(s);
                        if (search == _explored.cend()) {//new state
                            auto np = p;
                            np.push_back(s);
                            newPaths.insert(np);//new path with new state, keep going
                        }
                    }
                }
                oldPaths.insert(p);
            }

            for (auto p : oldPaths) {
                _paths.erase(p);
            }
            for (auto p : newPaths) {
                _paths.insert(p);
            }
            --steps;
        }
    }
    void show_solutions()
    {
        for (auto path : _solutions) {
            for (auto state : path) {
                show_state(state);
            }
            cout << "\n";
        }
    }
};


int main()
{
    vector<int> jugs = {3, 5};
    Pouring problem(jugs);
    problem.solve(4, 8);
    problem.show_solutions();
}

/*
using State = vector<int>;
class Pouring
{
private:
    vector<int> _capacities;  // capacity of each glass
    set<list<State>> _paths;  // trial paths in progress
    set<State> _explored;     // explored states
    set<list<State>> _solutions;
public:
    // specify the capacity of each glass
    Pouring(vector<int> cp): _capacities {cp} { }

    // There are three possible operations:
    // 1) empty the glass;
    // 2) fill the glass;
    // 3) pour from one glass to another.
    State Empty(State s, int glass)
    {
        s.at(glass) = 0;
        return s;
    }
    State Fill(State s, int glass)
    {
        s.at(glass) = _capacities.at(glass);
        return s;
    }
    State Pour(State s, int from, int to)
    {
        int diff = _capacities.at(to) - s.at(to);
        if (s.at(from) < diff) {  // all in
            s.at(to) += s.at(from);
            s.at(from) = 0;
        } else { // fill up as much as possible
            s.at(to) = _capacities.at(to);
            s.at(from) -= diff;
        }
        return s;
    }
    set<State> extend(State s)
    {
        set<State> nextStates;
        int nglasses = _capacities.size();

        for (int g=0; g < nglasses; g++) {
            nextStates.insert(Empty(s, g));
            nextStates.insert(Fill(s, g));
            for (int t=0; t < nglasses; t++) {
                if (t!=g)
                    nextStates.insert(Pour(s, g, t));
            }
        }
        return nextStates;
    }
    bool found(State s, int target)
    {
        for (auto c : s) {
            if (c==target) return true;
        }
        return false;
    }
    void solve(int target, int steps)
    {
        list<State> initialPath;
        initialPath.push_back(State(_capacities.size()));
        _paths.insert(initialPath);

        while (steps>0) {
            set<list<State>> newPaths;
            set<list<State>> oldPaths;

            for (auto p : _paths) {
                auto nextStates = extend(p.back());
                _explored.insert(p.back());
                for (auto s : nextStates) {
                    if (found(s, target)) {
                        auto np = p;
                        np.push_back(s);
                        _solutions.insert(np);
                    } else {
                        auto search = _explored.find(s);
                        if (search == _explored.cend()) {
                            auto np = p;
                            np.push_back(s);
                            newPaths.insert(np);
                        }
                    }
                }
                oldPaths.insert(p);
            }

            for (auto p : oldPaths) {
                _paths.erase(p);
            }
            for (auto p : newPaths) {
                _paths.insert(p);
            }

            --steps;
        }
    }
    void show_solutions()
    {
        for (auto path : _solutions) {
            for (auto state : path) {
                if (!state.empty()) {
                    ostringstream ss;
                    copy(state.cbegin(), state.cend()-1,
                         ostream_iterator<int>(ss, ","));
                    ss << state.back();
                    cout << ss.str() << " --> ";
                }
            }
            cout << "done" << endl;
        }
    }
};

int main()
{
    vector<int> glasses = {5, 3, 7};
    Pouring p(glasses);
    p.solve(6, 5);
    p.show_solutions();
}

*/
