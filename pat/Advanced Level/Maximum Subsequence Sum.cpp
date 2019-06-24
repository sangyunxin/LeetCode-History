#include <iostream>

using namespace std;

int K, num[10100], tmpsum, tmps, s, t, res;

int main()
{
    cin >> K;
    tmpsum = tmps = s = 0;
    res = -1;
    t = K - 1;
    for(int i = 0; i < K; i++){
        cin >> num[i];

        tmpsum += num[i];

        if(tmpsum < 0){
            tmpsum = 0;
            tmps = i + 1;
        }else if(tmpsum > res){
            res = tmpsum;
            s = tmps;
            t = i;
        }
    }

    if(res < 0)
        res = 0;
    cout << res << " " << num[s] << " " << num[t] << endl;
    return 0;
}
