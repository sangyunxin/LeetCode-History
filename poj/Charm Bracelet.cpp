#include <iostream>
#include <cstring>

using namespace std;

int dp[12900], W[3500], D[3500];
int N, M;

int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> W[i] >> D[i];

    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < N; i++){
        for(int j = M; j >= W[i]; j--)
            dp[j] = max(dp[j], dp[j-W[i]]+D[i]);
    }

    cout << dp[M] << endl;
    return 0;
}
