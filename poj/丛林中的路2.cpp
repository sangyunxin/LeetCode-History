#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 0x3f3f3f3f;

struct Node{
    int v, len;

    bool operator <(const Node & a) const{
        return len > a.len;
    }
};

priority_queue<Node> q;
int n, res, dis[35], vis[35];
vector<Node> G[35];

void init(){
    res = 0;

    while(!q.empty())
        q.pop();

    for(int i = 0; i < n; i++)
        G[i].clear();

    memset(vis, 0, sizeof(vis));
    memset(dis, MAX, sizeof(dis));
}

void prim(int s){
    Node n = {s, 0};
    q.push(n);
    while(!q.empty()){
        n = q.top(); q.pop();
        int v = n.v;
        if(vis[v] == 1)
            continue;

        res += n.len;
        vis[v] = 1;

        for(int i = 0; i < G[v].size(); i++){
            int v2 = G[v][i].v;
            int len = G[v][i].len;
            if(vis[v2] == 0 && dis[v2] > len){
                dis[v2] = len;
                Node tmp = {v2, len};
                q.push(tmp);
            }
        }
    }
}

int main()
{
    cin >> n;
    while(n != 0){
        init();

        for(int i = 0; i < n - 1; i++){
            char u;
            int k;
            cin >> u >> k;
            for(int j = 0; j < k; j++){
                char v;
                int cost;
                cin >> v >> cost;
                Node n = {v-'A', cost};
                G[u-'A'].push_back(n);
                n = {u-'A', cost};
                G[v-'A'].push_back(n);
            }
        }

        prim(0);

        cout << res << endl;

        cin >> n;
    }
    return 0;
}
