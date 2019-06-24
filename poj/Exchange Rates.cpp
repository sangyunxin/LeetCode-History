#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

int n;
double rate[400];
double dp[400][2];

double cut(double d){
    double tmp = floor(d * 100);
    return tmp / 100;
}

int main()
{
    cin >> n;

    while(n != 0){
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i <= n; i++)
            cin >> rate[i];

        dp[1][1] = 1000;
        dp[1][0] = 0;
        for(int i = 2; i <= n+1; i++){
            dp[i][1] = max(dp[i-1][1], cut(dp[i-1][0] * 0.97 * rate[i-1]));
            dp[i][0] = max(dp[i-1][0], cut(dp[i-1][1] * 0.97 / rate[i-1]));
        }

        printf("%.2f\n", dp[n+1][1]);
        cin >> n;

    }
    //cout << "Hello world!" << endl;
    return 0;
}
