#include <iostream>
#include <vector>
#include <list>
#include <set>

using std::vector;
using std::set;
using std::list;
using std::cout;
using std::endl;

// A state contains five components:
// The first two components denote the current numbers of
// missionaries and cannibals at the left bank of the river.
// The third and fourth components denote the current numbers
// of missionaries and cannibals at the right bank.
// The fifth component denotes the location of the boat:
// 1 means "left bank" and -1 means "right bank".
using State = vector<int>;
class Crossing
{
private:
    vector<int> _npeople;  // how many missionaries and cannibals
                           // we use vector<int> as a tuple (int, int)
                           // the first integer indicate the number of missionaries
                           // the second integer indicates the number of cannibals
    set<list<State>> _paths;  // trial paths in progress
    set<State> _explored;     // explored states
    set<list<State>> _solutions;
public:
    // specify the numbers of missionaries and cannibals
    Crossing(vector<int> np): _npeople {np} { }
    // the starting porint of your implementation
    void solve();
    // extend to other possible states from a certain state
    set<State> extend(State s);
    // may use s[4] to indicate the direction of move
    State Go(State s, int missionary, int cannibal);
    // check the validity of a state
    bool valid(State s);
    // check if all people are at the right bank
    bool found(State s);
    void show_solutions() {
        for (auto path : _solutions) {
            for (auto s : path) {
                if (!s.empty()) {
                    cout << "(" << s[0] << ", " << s[1] << ")";
                    cout << "(" << s[2] << ", " << s[3] << ")";
                    if (s[4]==1) cout << " left\n";
                    else cout << " right\n";
                }
            }
            cout << "done" << endl;
        }
    }
};