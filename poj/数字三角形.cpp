#include <iostream>

using namespace std;

int num[110][110];
int dp[110][110];
int N;

int main()
{
    cin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= i; j++){
            cin >> num[i][j];
        }
    }

    for(int i = 1; i <= N; i++){
        dp[i][1] = num[i][1] + dp[i-1][1];
        for(int j = 2; j <= i; j++){
            dp[i][j] = num[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
        }
    }

    int res = 0;
    for(int j = 1; j <= N; j++){
        if(res < dp[N][j])
            res = dp[N][j];
    }

    cout << res << endl;
    return 0;
}
