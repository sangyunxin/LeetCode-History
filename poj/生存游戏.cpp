#include <iostream>

using namespace std;

int n, m;
int s[110][110];
int e[110][110];

int isLive(int x, int y){
    int sum = s[x-1][y] + s[x-1][y-1] + s[x-1][y+1] + s[x][y-1] + s[x][y+1] + s[x+1][y] + s[x+1][y-1] + s[x+1][y+1];
    return sum;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> s[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int sum = isLive(i, j);
            if(s[i][j] == 1){
                if(sum < 2 || sum > 3)
                    e[i][j] = 0;
                else if(sum == 2 || sum == 3)
                    e[i][j] = 1;
            }else{
                if(sum == 3)
                    e[i][j] = 1;
                else
                    e[i][j] = 0;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j < m; j++){
            cout << e[i][j] << " ";
        }
        cout << e[i][m] << endl;
    }

    return 0;
}
