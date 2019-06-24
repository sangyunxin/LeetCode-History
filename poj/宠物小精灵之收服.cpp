#include <iostream>
#include <cstring>

using namespace std;

int N, M, K, n[1010], m[510], dp[1010][510];

int main()
{
    cin >> N >> M >> K;
    for(int i = 1; i <= K; i++)
        cin >> n[i] >> m[i];

    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= K; i++)
        for(int j = N; j >= n[i]; j--)
            for(int k = M; k >= m[i]; k--)
                dp[j][k] = max(dp[j][k], dp[j-n[i]][k-m[i]]+1);

    int i;
    for(i = 0; i <= M; i++){
        if(dp[N][i] == dp[N][M])
            break;
    }

    cout << dp[N][M] << " " << M-i << endl;
    return 0;
}
