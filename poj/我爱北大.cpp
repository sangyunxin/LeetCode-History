#include <iostream>
#include <map>
#include <string>
#include <cstring>
#define MAX 0x3f3f3f3f

using namespace std;

int P, Q, R;
map<string, int> pos;
map<int, string> ind;
int dis[50][50];
int pi[50][50];

void floyd(){
    for(int k = 0; k < P; k++){
        for(int i = 0; i < P; i++){
            for(int j = 0; j < P; j++){
                if(dis[i][j] > dis[i][k] + dis[k][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                    pi[i][j] = pi[k][j];
                }
            }
        }
    }
}

void output(int sp, int dp){
    if(sp == dp){
        cout << ind[sp];
        return;
    }
    output(sp, pi[sp][dp]);
    cout << "->(" << dis[pi[sp][dp]][dp] << ")->" << ind[dp];
}

int main()
{
    memset(dis, MAX, sizeof(dis));
    memset(pi, -1, sizeof(pi));

    cin >> P;
    for(int i = 0; i < P; i++){
        string p;
        cin >> p;
        pos[p] = i;
        ind[i] = p;
    }

    for(int i = 0; i < P; i++){
        dis[i][i] = 0;
        pi[i][i] = i;
    }

    cin >> Q;
    for(int i = 0; i < Q; i++){
        string s, d;
        int dist;
        cin >> s >> d >> dist;
        if(dist < dis[pos[s]][pos[d]]){
            dis[pos[d]][pos[s]] = dis[pos[s]][pos[d]] = dist;
            pi[pos[d]][pos[s]] = pos[d];
            pi[pos[s]][pos[d]] = pos[s];
        }
    }

    floyd();

    cin >> R;
    for(int i = 0; i < R; i++){
        string s, d;
        cin >> s >> d;
        int sp = pos[s];
        int dp = pos[d];
        output(sp, dp);
        cout << endl;
    }
    return 0;
}
