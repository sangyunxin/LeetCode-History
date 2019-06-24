#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int N, K, num[10010];
bool dp[10010][110];

int main()
{
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> num[i];
        num[i] = (int)abs(num[i]) % K;
    }

    memset(dp, false, sizeof(dp));

    dp[1][num[1]] = true;

    for(int i = 2; i <= N; i++)
        for(int j = 0; j < K; j++)
            if(dp[i-1][j]){
                dp[i][(j+num[i])%K] = true;
                dp[i][((j-num[i])%K+K)%K] = true;
            }

    if(dp[N][0])
        cout << "Divisible" << endl;
    else
        cout << "Not divisible" << endl;

    return 0;
}
