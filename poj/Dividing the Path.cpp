#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 0x3f3f3f3f;

int N, L, A, B, S[1010], E[1010], dp[1000010], CC[1000010];

int main()
{
    cin >> N >> L >> A >> B;

    memset(dp, MAX, sizeof(dp));
    memset(CC, 0, sizeof(CC));

    for(int i = 0; i < N; i++){
        cin >> S[i] >> E[i];
        for(int j = S[i] + 1; j < E[i]; j++){
            CC[j]++;
        }
    }

    if(L % 2 != 0)
        cout << "-1" << endl;
    else{
        for(int x = 2 * A; x <= L; x += 2){
            if(CC[x] != 0)
                continue;
            else if(x <= 2 * B)
                dp[x] = 1;
            else{
                int minp = MAX;
                for(int y = x - 2 * B; y <= x - 2 * A; y += 2)
                    minp = min(minp, dp[y]);
                dp[x] = minp + 1;
            }
        }
    }


//    for(int i = 0; i <= L; i++){
//        cout << dp[i] << " ";
//    }

    //cout << endl;

    if(dp[L] < MAX)
        cout << dp[L] << endl;
    else
        cout << "-1" << endl;

    return 0;
}
