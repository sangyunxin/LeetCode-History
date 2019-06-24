#include <iostream>

using namespace std;

int N, pre, cur, res;

int main()
{
    cin >> N;
    res = pre = cur = 0;
    for(int i = 0; i < N; i++){
        cin >> cur;

        if(cur > pre)
            res += ((cur - pre) * 6);
        else if(cur < pre)
            res += ((pre - cur) * 4);

        //cout << pre << " " << cur << " " << res << endl;

        pre = cur;
    }

    res += 5 * N;

    cout << res << endl;
    return 0;
}
