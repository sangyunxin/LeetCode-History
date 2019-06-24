#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 0x3f3f3f3f;

int N, M, X;
int w1[1010][1010], w2[1010][1010];
int p1[1010], p2[1010], vis1[1010], vis2[1010];

void dijkstra(int v0, bool flag){
    if(flag){
        for(int i = 1; i <= N; i++){
            p1[i] = w1[v0][i];
        }
        p1[v0] = 0;
        vis1[v0] = 1;
        for(int i = 1; i <= N; i++){
            int minp = MAX;
            int v = -1;
            for(int j = 1; j <= N; j++){
                if(vis1[j] == 0 && minp > p1[j]){
                    minp = p1[j];
                    v = j;
                }
            }

                if(v == -1)
                    return;

                vis1[v] = 1;
                for(int j = 1; j <= N; j++){
                    if(vis1[j] == 0 && minp + w1[v][j] < p1[j])
                        p1[j] = minp + w1[v][j];
                }
            }
    }else{
        for(int i = 1; i <= N; i++){
            p2[i] = w2[v0][i];
        }
        p2[v0] = 0;
        vis2[v0] = 1;
        for(int i = 1; i <= N; i++){
            int minp = MAX;
            int v = -1;
            for(int j = 1; j <= N; j++){
                if(vis2[j] == 0 && minp > p2[j]){
                    minp = p2[j];
                    v = j;
                }
            }

                if(v == -1)
                    return;

                vis2[v] = 1;
                for(int j = 1; j <= N; j++){
                    if(vis2[j] == 0 && minp + w2[v][j] < p2[j])
                        p2[j] = minp + w2[v][j];
                }
            }
        }

}

int main()
{
    memset(w1, MAX, sizeof(w1));
    memset(w2, MAX, sizeof(w2));
    cin >> N >> M >> X;
    for(int i = 0; i < M; i++){
        int a, b, t;
        cin >> a >> b >> t;
        w1[a][b] = t;
        w2[b][a] = t;
    }

    dijkstra(X, true);
    dijkstra(X, false);

    int result = 0;
    for(int i = 1; i <= N; i++){
        if(p1[i] + p2[i] > result)
            result = p1[i] + p2[i];
     }

    cout << result << endl;

    return 0;
}
