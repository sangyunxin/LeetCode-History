#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int K, N, resK;
float a;
map<int, float, greater<int> > res;
map<int, float>::iterator iter;

int main()
{
    for(int i = 0; i < 2; i++){
        cin >> K;
        for(int j = 0; j < K; j++){
            cin >> N >> a;
            iter = res.find(N);
            if(iter != res.end())
                res[N] += a;
            else
                res[N] = a;
        }
    }

    resK = 0;
    for(iter = res.begin(); iter != res.end(); iter++){
        if(iter->second != 0.0)
            resK++;
    }

    printf("%d", resK);
    for(iter = res.begin(); iter != res.end(); iter++){
        if(iter->second != 0.0)
            printf(" %d %.1f", iter->first, iter->second);
    }
    return 0;
}
