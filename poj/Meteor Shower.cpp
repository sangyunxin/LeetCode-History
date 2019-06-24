#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int M;
int area[350][350];
int vis[350][350];
int dx[] = {0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};

struct Node{
    int x, y, time;
};

queue<Node> q;

void change(int x, int y, int time){
    area[x][y] = min(area[x][y], time);
    if(x > 0)
        area[x-1][y] = min(area[x-1][y], time);
    if(x < 300)
        area[x+1][y] = min(area[x+1][y], time);
    if(y > 0)
        area[x][y-1] = min(area[x][y-1], time);
    if(y < 300)
        area[x][y+1] = min(area[x][y+1], time);
}

int bfs(){
    while(!q.empty()){
        Node n = q.front();
        q.pop();
        for(int i = 0; i < 5; i++){
            int curx = n.x + dx[i];
            int cury = n.y + dy[i];
            int curt = n.time + 1;
            if(curx < 0 || cury < 0 || vis[curx][cury] == 1 || curt >= area[curx][cury])
                continue;
            if(area[curx][cury] > 1000)
                return curt;
            vis[curx][cury] = 1;
            Node tmp = {curx, cury, curt};
            q.push(tmp);
        }
    }

    return -1;
}

int main()
{
    memset(area, 10000, sizeof(area));
    memset(vis, 0, sizeof(vis));
    cin >> M;
    for(int i = 0; i < M; i++){
        int x, y, time;
        cin >> x >> y >> time;
        change(x, y, time);
    }

    if(area[0][0] > 1000)
        cout << 0 << endl;
    else if(area[0][0] == 0)
        cout << -1 << endl;
    else{
        Node start = {0, 0, 0};
        q.push(start);
        vis[0][0] = 1;
        int result = bfs();
        cout << result << endl;
    }
    return 0;
}
