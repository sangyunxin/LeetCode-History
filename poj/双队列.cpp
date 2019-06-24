#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int k, p;

    bool operator <(const Node & a) const{
        return p < a.p;
    }
};

struct cmp{
    bool operator ()(const Node & a, const Node & b){
        return a.p > b.p;
    }
};

priority_queue<Node> q1;
priority_queue<Node, vector<Node>, cmp> q2;
int num, t;

int main()
{
    cin >> t;
    num = 0;
    while(t != 0){
        if(t == 1){
            Node cur;
            cin >> cur.k >> cur.p;
            q1.push(cur);
            q2.push(cur);
            num++;
        }else if(t == 2){
            if(num > 0){
                cout << q1.top().k << endl;
                q1.pop();
                num--;
            }else{
                cout << 0 << endl;
            }
        }else if(t == 3){
            if(num > 0){
                cout << q2.top().k << endl;
                q2.pop();
                num--;
            }else{
                cout << 0 << endl;
            }
        }
        cin >> t;
    }
    return 0;
}
