#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX = 0x3f3f3f3f;
int path[25][25];
int n, x, no;

void floyd(){
    for(int k = 1; k <= 20; k++)
        for(int i = 1; i <= 20; i++)
            for(int j = 1; j <= 20; j++)
                path[i][j] = min(path[i][j], path[i][k]+path[k][j]);
}

int main()
{
    no = 0;
    while(true){
        memset(path, MAX, sizeof(path));

        for(int i = 1; i <= 19; i++){
            path[i][i] = 0;
            if(!(cin >> x)) return 0;
            for(int j = 0; j < x; j++){
                int v;
                cin >> v;
                path[i][v] = 1;
                path[v][i] = 1;
            }
        }

        path[20][20] = 0;

        floyd();

        if(!(cin >> n)) return 0;
        no++;
        cout << "Test Set #" << no << endl;
        for(int i = 0; i < n; i++){
            int u, v;
            cin >> u >> v;
            cout << u << " to " << v << ": " << path[u][v] << endl;
        }
        cout << endl;
    }
    //cout << "Hello world!" << endl;
    return 0;
}
