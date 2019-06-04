#include <iostream>
#include <vector>
#include <list>
#include <set>
#include "function.h"
using std::vector;
using std::set;
using std::list;
using std::cout;
using std::endl;


// the starting porint of your implementation
void Crossing::solve()
{
    list<State> _initpath;
    State init;
    init = _npeople;
    init.push_back(0);
    init.push_back(0);
    init.push_back(1);
    _initpath.push_back(init);
    _paths.insert(_initpath);

    while (!_paths.empty()) {
        set <list<State>> _newpath;
        set <list<State>> _oldpath;
        for (auto p: _paths) {
            _explored.insert(p.back());
            auto nxtState = extend(p.back());
            for (auto s:nxtState) {
                if (found(s)) {
                    auto np = p;
                    np.push_back(s);
                    _solutions.insert(np);
                } else {
                    if (_explored.find(s)==_explored.end()) {
                        auto np = p;
                        np.push_back(s);
                        _newpath.insert(np);
                    }
                }
            }
            _oldpath.insert(p);
        }

        for (auto p : _oldpath) {
            _paths.erase(p);
        }
        for (auto p : _newpath) {
            _paths.insert(p);
        }
    }
}
// extend to other possible states from a certain state
set<State> Crossing::extend(State s)
{
    set <State> ss;
    if (valid(Go(s, 2, 0))) ss.insert(Go(s, 2, 0));
    if (valid(Go(s, 0, 2))) ss.insert(Go(s, 0, 2));
    if (valid(Go(s, 1, 1))) ss.insert(Go(s, 1, 1));
    if (valid(Go(s, 1, 0))) ss.insert(Go(s, 1, 0));
    if (valid(Go(s, 0, 1))) ss.insert(Go(s, 0, 1));
    //cout<<endl;
    return ss;
}
// may use s[4] to indicate the direction of move
State Crossing::Go(State s, int missionary, int cannibal)
{

    if ((s[4]==1&&s[0]>=missionary&&s[1]>=cannibal) || (s[4]==-1&&s[2]>=missionary&&s[3]>=cannibal)) {
        s[0] = s[0] - s[4]*missionary;
        s[1] = s[1] - s[4]*cannibal;
        s[2] = s[2] + s[4]*missionary;
        s[3] = s[3] + s[4]*cannibal;
        s[4] = -s[4];
    }
    //cout<<"s:"<<s[0]<<s[1]<<s[2]<<s[3]<<endl;
    return s;
}

// check the validity of a state
bool Crossing::valid(State s)
{
    if ((s[0]>=s[1]||s[0]==0)&&(s[2]>=s[3]||s[2]==0)) return true;
    else return false;
}
// check if all people are at the right bank
bool Crossing::found(State s)
{
    if (s[0]==0&&s[1]==0) return true;
    else return false;
}
