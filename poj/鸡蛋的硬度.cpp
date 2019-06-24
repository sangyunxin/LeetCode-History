#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 0x3f3f3f3f;
int m, n;
int dp[110][15];

int main()
{
    memset(dp, MAX, sizeof(dp));
    for(int i = 1; i <= 100; i++){
        dp[i][1] = i;
    }

    for(int i = 1; i <= 10; i++){
        dp[1][i] = 1;
        dp[0][i] = 0;
    }

    for(int i = 2; i <= 100; i++){
        for(int j = 2; j <= 10; j++){
            for(int k = 1; k < i; k++){
                dp[i][j] = min(dp[i][j], max(dp[i-k][j-1]+1, dp[k-1][j]+1));
            }
        }
    }

    cin >> n >> m;
    cout << dp[n][m] << endl;
    return 0;
}
