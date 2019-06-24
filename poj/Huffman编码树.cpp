#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int val, index, pre1, pre2;

    bool operator <(const Node & a) const{
        return val > a.val;
    }
} nodes[500];

priority_queue<Node> q;
int t, n, res;

void getW(Node & root, int L){
    if(root.pre1 == -1 && root.pre2 == -1)
        res += root.val * L;
    if(root.pre1 != -1)
        getW(nodes[root.pre1], L+1);
    if(root.pre2 != -1)
        getW(nodes[root.pre2], L+1);
}

int main()
{

    while(!q.empty())
        q.pop();

    cin >> n;
    for(int j = 0; j < n; j++){
        int val;
        cin >> val;
        nodes[j] = {val, j, -1, -1};
        q.push(nodes[j]);
    }

    int k = n;
    Node n1 = q.top();
    q.pop();
    while(!q.empty()){
        Node n2 = q.top();
        q.pop();
        nodes[k] = {n1.val + n2.val, k, n1.index, n2.index};
        q.push(nodes[k++]);
        n1 = q.top();
        q.pop();
    }

    res = 0;
    getW(n1, 0);
    cout << res << endl;
    //cout << "Hello world!" << endl;
    return 0;
}
