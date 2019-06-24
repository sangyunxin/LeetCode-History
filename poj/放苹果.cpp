#include <iostream>

using namespace std;

int res, t;
int M, N;

void bt(int m, int n, int k){
    if(m < 0 || n < 0)
        return;
    if(m == 0 && n == 0){
        res++;
        return;
    }
    for(int i = k; i <= m; i++){
        bt(m-i, n-1, i);
    }
}

int main()
{
    cin >> t;
    for(int i = 0; i < t; i++){
        res = 0;
        cin >> M >> N;
        bt(M, N, 0);
        cout << res << endl;
    }
    return 0;
}
