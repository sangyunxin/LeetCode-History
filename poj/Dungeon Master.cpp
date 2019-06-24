#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dun[35][35][35];
int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {1, -1, 0, 0, 0, 0};
int dz[] = {0, 0, 1, -1, 0, 0};
int L, R, C, res, sx, sy, sz, ex, ey, ez;
int vis[35][35][35];

struct Node{
    int x, y, z, t;

    bool operator<(const Node a) const{
        return t > a.t;
    }
};

priority_queue<Node> q;

int bfs(){
    while(!q.empty()){
        Node n = q.top();
        q.pop();

        for(int i = 0; i < 6; i++){
            int curz = n.z + dz[i];
            int cury = n.y + dy[i];
            int curx = n.x + dx[i];
            int curt = n.t + 1;

            if(curz < 1 || curx < 1 || cury < 1 || curz > L || curx > R || cury > C)
                continue;

            if(vis[curz][curx][cury] == 1 || dun[curz][curx][cury] == 1)
                continue;

            if(curz == ez && curx == ex && cury == ey)
                return curt;

            Node tmp = {curx, cury, curz, curt};
            vis[curz][curx][cury] = 1;
            q.push(tmp);
        }
    }

    return -1;
}

int main()
{
    cin >> L >> R >> C;
    while(L != 0 && R != 0 && C != 0){
        memset(dun, 0, sizeof(dun));
        memset(vis, 0, sizeof(vis));

        while(!q.empty())
            q.pop();

        for(int z = 1; z <= L; z++){
            for(int x = 1; x <= R; x++){
                for(int y = 1; y <= C; y++){
                    char c;
                    cin >> c;
                    if(c == '#')
                        dun[z][x][y] = 1;
                    else if(c == 'S'){
                        sz = z;
                        sx = x;
                        sy = y;
                    }else if(c == 'E'){
                        ez = z;
                        ex = x;
                        ey = y;
                    }
                }
            }
        }

        Node n = {sx, sy, sz, 0};
        vis[sz][sx][sy] = 1;
        q.push(n);
        res = bfs();

        //cout << res << endl;
        if(res != -1)
            cout << "Escaped in " << res << " minute(s)." << endl;
        else
            cout << "Trapped!" << endl;

        cin >> L >> R >> C;
    }
    return 0;
}
