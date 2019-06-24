#include <iostream>
#include <cstring>

using namespace std;
int row, col;
int x[150][150];
int vis[150][150];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main()
{
    cin >> row >> col;
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            cin >> x[i][j];
        }
    }

    int dirc = 0;
    memset(vis, 0, sizeof(vis));
    int sx = 1, sy = 1;

    while(vis[sx][sy] != 1){
        cout << x[sx][sy] << endl;
        vis[sx][sy] = 1;

        int curx = sx + dx[dirc];
        int cury = sy + dy[dirc];

        if(curx < 1 || curx > row || cury < 1 || cury > col || vis[curx][cury] == 1){
            dirc = (dirc + 1) % 4;
        }

        sx = sx + dx[dirc];
        sy = sy + dy[dirc];

        //cout << vis[sx][sy] << endl;
    }

    return 0;
}
