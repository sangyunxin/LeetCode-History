#include <iostream>
#include <map>
#include <cstring>

using namespace std;
//const int MAX = 0x3f3f3f3f;

int n, m;
double dist[50];
map<string, int> pos;

struct Edge{
    int u, v;
    double r;
}e[1000];

bool relax(){
    bool flag = false;
    for(int i = 1; i <= m; i++){
        if(dist[e[i].v] < dist[e[i].u] * e[i].r){
            dist[e[i].v] = dist[e[i].u] * e[i].r;
            flag = true;
        }

//        if(dist[e[i].u] < dist[e[i].v] / e[i].r){
//            dist[e[i].u] = dist[e[i].v] / e[i].r;
//            flag = true;
//        }
    }

    return flag;
}

bool bellmanford(){
    //memset(dist, MAX, sizeof(dist));
    dist[1] = 1;

    for(int i = 1; i <= n; i++){
        if(!relax())
            return false;
    }

    return true;
}

int main()
{
    cin >> n;
    int c = 1;
    while(n != 0){
        pos.clear();
        memset(dist, 0, sizeof(dist));
        for(int i = 1; i <= n; i++){
            string s;
            cin >> s;
            pos[s] = i;
        }

        cin >> m;
        for(int i = 1; i <= m; i++){
            string s, d;
            double r;
            cin >> s >> r >> d;
            e[i].u = pos[s];
            e[i].v = pos[d];
            e[i].r = r;
        }

        if(bellmanford())
            cout << "Case " << c << ": Yes" << endl;
        else
            cout << "Case " << c << ": No" << endl;

//        for(int i = 1; i <= m; i++){
//            cout << dist[i] << " ";
//        }
//        cout << endl;
        cin >> n;
        c++;
    }

    //cout << "Hello world!" << endl;
    return 0;
}
