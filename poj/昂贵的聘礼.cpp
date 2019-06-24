#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 0x3f3f3f3f;

int M, N;

struct Node{
    int p, l, x;
} nodes[150];

int path[150][150];
int dist[150];
int vis[150];

void dijkstra(){
    memset(dist, MAX, sizeof(dist));
    dist[1] = 0;

    for(int i = 1; i <= N; i++){
        int mind = MAX;
        int v = -1;
        for(int j = 1; j <= N; j++){
            if(vis[j] == 0 && dist[j] < mind)
                mind = dist[v=j];
        }

        vis[v] = 1;

        for(int j = 1; j <= N; j++){
            if(vis[j] == 0 && dist[j] > mind + path[v][j])
                dist[j] = mind + path[v][j];
        }
    }
}

int main()
{
    cin >> M >> N;
    memset(path, MAX, sizeof(path));
    for(int i = 1; i <= N; i++){
        cin >> nodes[i].p >> nodes[i].l >> nodes[i].x;
        for(int j = 0; j < nodes[i].x; j++){
            int t, v;
            cin >> t >> v;
            path[i][t] = v;
        }
    }

    int res = MAX;
    int king_lev = nodes[1].l;
    for(int j = 0; j <= M; j++){
        int sl = king_lev - j;
        int el = M + king_lev - j;
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= N; i++){
            if(nodes[i].l > el || nodes[i].l < sl)
                vis[i] = 1;
        }

        dijkstra();

        for(int i = 1; i <= N; i++){
            if(res > nodes[i].p + dist[i])
                res = nodes[i].p + dist[i];
        }
    }

    cout << res << endl;
    return 0;
}
