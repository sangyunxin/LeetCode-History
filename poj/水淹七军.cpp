#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int M, N, K, tx, ty, P;
int area[250][250];
int vis[250][250];
vector<int> X, Y;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct NODE{
    int x, y, h;
};

queue<NODE> q;

bool bfs(){
    while(!q.empty()){
        NODE n = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int curx = n.x + dx[i];
            int cury = n.y + dy[i];
            if(curx < 1 || curx > M || cury < 1 || cury > N || vis[curx][cury] == 1)
                continue;

            if(n.h <= area[curx][cury])
                continue;

            if(curx == tx && cury == ty)
                return true;

            NODE tmp = {curx, cury, n.h};
            q.push(tmp);
            vis[curx][cury] = 1;
        }
    }
}

int main()
{
    cin >> K;
    for(int i = 0; i < K; i++){
        bool flag = false;
        memset(area, 0, sizeof(area));
        X.clear();
        Y.clear();
        cin >> M >> N;
        for(int j = 1; j <= M; j++){
            for(int k = 1; k <= N; k++)
                cin >> area[j][k];
        }

        cin >> tx >> ty;
        cin >> P;

        for(int j = 0; j < P; j++){
            int x, y;
            cin >> x >> y;
            X.push_back(x);
            Y.push_back(y);
        }

        for(int j = 0; j < P; j++){
            while(!q.empty()){
                q.pop();
            }

            NODE n = {X[j], Y[j], area[X[j]][Y[j]]};
            vis[X[j]][Y[j]] = 1;
            q.push(n);
            if(bfs()){
                flag = true;
                break;
            }
        }

        if(flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
