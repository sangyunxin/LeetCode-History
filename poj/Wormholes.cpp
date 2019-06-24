#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 0x3f3f3f3f;

int F, N, M, W, E;
int dist[550];

struct Edge{
    int s, e, t;
}edges[3000];

bool relax(Edge & e, bool dire){
    bool flag = false;
    if(dist[e.e] > dist[e.s] + e.t){
        dist[e.e] = dist[e.s] + e.t;
        flag = true;
    }

    if(dire){
        if(dist[e.s] > dist[e.e] + e.t){
            dist[e.s] = dist[e.e] + e.t;
            flag = true;
        }
    }

    return flag;
}

bool bellmanford(){
    bool flag;
    dist[N] = 0;
    for(int i = 0; i < N; i++){
        bool flag = false;
        for(int j = 0; j < E; j++){
            if(relax(edges[j], j < M))
                flag = true;
        }
        if(!flag)
            return false;
    }

    return true;
}

int main()
{
    cin >> F;
    for(int i = 0; i < F; i++){
        memset(dist, MAX, sizeof(dist));
        cin >> N >> M >> W;
        E = 0;
        for(; E < M; E++){
            cin >> edges[E].s >> edges[E].e >> edges[E].t;
        }
        for(; E < M + W; E++){
            cin >> edges[E].s >> edges[E].e >> edges[E].t;
            edges[E].t = -1 * edges[E].t;
        }

        if(bellmanford())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

//        for(int j = 1; j <= N; j++)
//            cout << dist[j] << " ";
//        cout << endl;

    }
    return 0;
}
