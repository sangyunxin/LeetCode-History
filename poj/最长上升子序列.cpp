#include <iostream>

using namespace std;

int num[1010], dp[1010];
int N;

int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> num[i];
    }

    for(int j = 1; j <= N; j++){
        int maxp = 0;
        for(int i = 1; i < j; i++){
            if(num[i] < num[j] && dp[i] > maxp){
                maxp = dp[i];
            }
        }
        dp[j] = 1 + maxp;
    }

    int res = 1;
    for(int i = 1; i <= N; i++){
        if(dp[i] > res)
            res = dp[i];
    }

    cout << res << endl;

    return 0;
}
