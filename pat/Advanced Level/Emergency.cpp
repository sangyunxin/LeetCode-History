#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 0x3f3f3f3f;
int N, M, C1, C2, path[550][550], dist[550], vis[550], w[550], resw[550], num[550], s, t;

void dijkstra(){
    memset(dist, MAX, sizeof(dist));
    memset(resw, 0, sizeof(resw));
    memset(vis, 0, sizeof(vis));
    num[C1] = 1;
    dist[C1] = 0;
    resw[C1] = w[C1];

    for(int i = 0; i < N; i++){
        int mind = MAX;
        int v = -1;

        for(int j = 0; j < N; j++)
            if(mind > dist[j] && vis[j] == 0){
                mind = dist[j];
                v = j;
            }

        vis[v] = 1;

        for(int j = 0; j < N; j++){
            if(dist[j] > dist[v] + path[v][j] && vis[j] == 0){
                //cout << v << " " << j << " " << num[j] << " " << num[v] << endl;
                dist[j] = dist[v] + path[v][j];
                num[j] = num[v];
                resw[j] = resw[v] + w[j];
            }
            else if(dist[j] == dist[v] + path[v][j] && vis[j] == 0){
                //cout << v << " " << j << " " << num[v] << " " << num[j] << endl;
                num[j] += num[v];
                if(resw[j] < resw[v] + w[j])
                    resw[j] = resw[v] + w[j];
            }
        }

    }
}

int main()
{
    memset(path, MAX, sizeof(path));
    cin >> N >> M >> C1 >> C2;

    for(int i = 0; i < N; i++)
        cin >> w[i];

    for(int i = 0; i < M; i++){
        cin >> s >> t;
        cin >> path[s][t];
        path[t][s] = path[s][t];
    }

    dijkstra();

    cout << num[C2] << " " << resw[C2];

    //cout << "Hello world!" << endl;
    return 0;
}
