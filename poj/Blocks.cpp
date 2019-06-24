#include <iostream>
#include <cstring>

using namespace std;

int t, n, score[210][210][210], color[210], Len[210], L;

int clickBox(int i, int j, int extraLen){
    if(score[i][j][extraLen] != -1)
        return score[i][j][extraLen];

    if(i == j)
        return (Len[i] + extraLen) * (Len[i] + extraLen);

    int res = (Len[j] + extraLen) * (Len[j] + extraLen) + clickBox(i, j-1, 0);
    for(int k = i; k < j; k++){
        if(color[k] == color[j])
            res = max(res, clickBox(k+1, j-1, 0) + clickBox(i, k, Len[j]+extraLen));
    }

    score[i][j][extraLen] = res;

    return res;
}

int main()
{
    cin >> t;
    for(int i = 0; i < t; i++){
        memset(score, -1, sizeof(score));
        memset(Len, 0, sizeof(Len));
        memset(color, 0, sizeof(color));

        L = 0;
        int p = -1;

        cin >> n;
        for(int j = 1; j <= n; j++){
            int cur;
            cin >> cur;
            if(p != cur){
                p = cur;
                L++;
                color[L] = p;
            }
            Len[L]++;
        }

        int res = clickBox(1, L, 0);
        cout << "Case " << (i+1) << ": " << res << endl;
    }

    return 0;
}
