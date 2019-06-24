#include <iostream>
#include <cstring>

using namespace std;

char cases[25][25];
int vis[30];
int r, s, res;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y, int len){
    for(int i = 0; i < 4; i++){
        int curx = x + dx[i];
        int cury = y + dy[i];
        int pos = cases[curx][cury] - 'A';
        if(vis[pos] == 1 || curx < 1 || curx > r || cury < 1 || cury > s)
            continue;

        if(res < len)
            res = len;
        vis[pos] = 1;
        dfs(curx, cury, len+1);
        vis[pos] = 0;
    }
}

int main()
{
    memset(vis, 0, sizeof(vis));
    cin >> r >> s;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= s; j++)
            cin >> cases[i][j];
    }

    res = 0;
    vis[cases[1][1] - 'A'] = 1;

    dfs(1, 1, 1);

    cout << res+1 << endl;
    //cout << "Hello world!" << endl;
    return 0;
}
