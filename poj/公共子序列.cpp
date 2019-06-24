#include <iostream>
#include <cstring>

using namespace std;

char X[250], Y[250];
int dp[250][250];

int main()
{
    while(cin >> X >> Y){
        memset(dp, 0, sizeof(dp));
        int xLen = strlen(X);
        int yLen = strlen(Y);

        for(int m = 1; m <= xLen; m++){
            for(int n = 1; n <= yLen; n++){
                if(X[m-1] == Y[n-1])
                    dp[m][n] = dp[m-1][n-1] + 1;
                else
                    dp[m][n] = max(dp[m-1][n], dp[m][n-1]);
            }
        }

        cout << dp[xLen][yLen] << endl;
    }
    return 0;
}
