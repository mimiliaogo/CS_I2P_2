#include <iostream>
#include <vector>
#include <set>
#include <array>
#include <queue>
using namespace std;

struct Node {
    using State = array<int, 9>;

    State st;
    Node* parent;
    int level;

    Node(State input): st(input), level(0), parent(nullptr){};
    Node(State input, Node*p): st(input), level(p->level+1), parent(p) {};
};

class SlideGame
{
    using State = array<int, 9>;
private:
    State st;
    Node* sol;

public:
    SlideGame(State input): st(input), sol(nullptr) {};

    State MoveBlock(State s, int from, int to)
    {
        swap(s[to], s[from]);
        return s;
    }

    set<State> extend(State s)
    {
        set<State> SS;

        int pos, x, y;
        for (pos=0; pos<9; pos++) {
            if (s[pos]==0) {
                x = pos%3;
                y = pos/3;
                break;
            }
        }
        //right
        if (x<2) SS.insert(MoveBlock(s, pos, pos+1));
        //left
        if (x>0) SS.insert(MoveBlock(s, pos, pos-1));
        //up
        if (y>0) SS.insert(MoveBlock(s, pos, pos-3));
        //down
        if (y<2) SS.insert(MoveBlock(s, pos, pos+3));
        return SS;
    }

    bool found(State s)
    {
        for (int i=0; i<8; i++) {
            if (s[i]!=i+1) return false;
        }
        return true;

    }

    int solve()
    {
        queue<Node*> q;
        set <State> explored;
        Node* cur = new Node(st);
        Node* child;
        bool done = false;

        if (found(cur->st)) return 0;
        q.push(cur);
      //  explored.insert(cur->st);
        while (q.size()!=0&&!done) {
            cur = q.front();
            if (cur->level>=14) break;
            auto nextStates = extend(cur->st);
            for (auto s: nextStates) {
                if (found(s)) {
                    sol = new Node(s, cur);
                    done = true;
                    break;
                } else {
                    auto next = explored.find(s);
                    if (next==explored.end()) {
                        child = new Node(s, cur);
                        explored.insert(s);
                        q.push(child);
                    }
                }
            }
            q.pop();
        }

        if (done) return sol->level;
        else return -1;


    }



};

int main()
{

    int n;
    cin>>n;
    while (n>0) {
        n--;
        array<int, 9>p;
        for (int i=0; i<9; i++) {
            cin>>p[i];
        }
        SlideGame problem(p);
        int step = problem.solve();
        if (step>0&&step<=14)
            cout<<"You can solve it within "<<step<<" steps.\n";
        else
            cout << "You'd better skip this game.\n";
    }

}
