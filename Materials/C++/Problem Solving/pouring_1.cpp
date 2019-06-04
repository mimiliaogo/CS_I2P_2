#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <iterator>
#include <string>
#include <sstream>

using namespace std;
using State = vector<int>;

struct Node {
    State st;
    Node* parent;

    Node(State input): st(input), parent(nullptr){};
};

class Pouring
{
private:
    vector<int>  capacities;    // {3, 5}

public:
    Pouring(vector<int> cp): capacities{cp} { }

    State Empty(State s, int jug_no)
    {
        s[jug_no] = 0;
        return s;
    }

    State Fill(State s, int jug_no)
    {
        s[jug_no] = capacities[jug_no];
        return s;
    }

    State Pour(State s, int from, int to)
    {
        State t = s;
        int diff = capacities[to]-s[to];
        if (diff < s[from]) {
            t[to] = capacities[to];
            t[from] = s[from]-diff;
        } else {
            t[from] = 0;
            t[to] = s[to] + s[from];
        }
        return t;
    }

    set<State> extend(State s)
    {
        set<State> SS;
        for (unsigned int i=0; i< capacities.size(); ++i) {
            SS.insert(Empty(s, i));
            SS.insert(Fill(s, i));
            for (unsigned int j=0; j< capacities.size(); ++j) {
                if (i!=j)
                    SS.insert(Pour(s, i, j));
            }
        }
        return SS;
    }

    bool found(State s, int target)
    {
        for (auto t : s) {
            if (t==target) return true;
        }
        return false;
    }

    void show_state(State s)
    {
        unsigned int i, ss = s.size()-1;
        cout << "(";
        for (i=0; i<ss; i++)
            cout << s[i] << "," ;
        cout << s.back() <<")";
    }

    void show_solutions(Node* current, State st) {
        Node* temp = current;
        vector<State> sol;
        int i;

        while (temp != nullptr){ // back tracking
            sol.push_back(temp->st);
            temp = temp->parent;
        }

        for(i=sol.size()-1; i>=0; i--){
            show_state(sol[i]);
            cout << "->";
        }
        show_state(st);
        cout << endl;
    }


    void solve(int target)
    {
        queue<Node*>  q;
        set<State>   explored;      // the states appeared before
        Node* current = new Node(State(capacities.size()));
        Node* child;
        bool done = false;

        q.push(current);
        explored.insert(current->st);

        while(q.size()!=0 && !done) {
            current = q.front();
            auto nextStates = extend(current->st);      // find all possible states
            for (auto s : nextStates) {
                if (found(s, target)) {                 // found a solution
                    show_solutions(current, s);
                    done = true;
                } else {                                // not a solution
                    auto next = explored.find(s);
                    if (next == explored.cend()) {      // a new node
                        child = new Node(s);
                        child->parent = current;
                        explored.insert(s);
                        q.push(child);
                    }
                }
            }
            q.pop();
        }
    }
};


int main()
{
    vector<int> jugs = {3, 5};
    Pouring problem(jugs);
    problem.solve(4);
}
