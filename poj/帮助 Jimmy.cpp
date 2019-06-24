#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXH = 0x3f3f3f3f;

struct NODE{
    int l, r, h;

    bool operator<(const NODE & a) const{
        return h < a.h;
    }
} nodes[1100];

int t, N, X, Y, MAX;
int dp[1100][2];

int findD(int p, int i){
    for(int j = i - 1; j >= 0; j--){
        if(p >= nodes[j].l && p <= nodes[j].r)
            return j;
    }

    return -1;
}

int getDP(int p, int j){
    int d = findD(p, j);
    if(d == -1){
        if(nodes[j].h <= MAX)
            return nodes[j].h;
        else
            return MAXH;
    }else if(nodes[j].h - nodes[d].h > MAX)
        return MAXH;
    else
        return nodes[j].h - nodes[d].h + min(dp[d][0] + p - nodes[d].l, dp[d][1] + nodes[d].r - p);
}

int main()
{
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> N >> X >> Y >> MAX;

        for(int j = 0; j < N; j++)
            cin >> nodes[j].l >> nodes[j].r >> nodes[j].h;

        nodes[N] = {X, X, Y};

        sort(nodes, nodes+N+1);
        memset(dp, MAXH, sizeof(dp));

        for(int j = 0; j <= N; j++){
            dp[j][0] = getDP(nodes[j].l, j);
            dp[j][1] = getDP(nodes[j].r, j);
        }

//        int d = findD(X, N);
//        int res = Y - nodes[d].h + min(dp[d][0] + X - nodes[d].l, dp[d][1] + nodes[d].r - X);
        cout << min(dp[N][0], dp[N][1]) << endl;
    }
    return 0;
}
