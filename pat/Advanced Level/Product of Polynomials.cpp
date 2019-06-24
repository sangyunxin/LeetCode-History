#include <iostream>
#include <map>
#include <cstring>
#include <cstdio>

using namespace std;
int K1, K2, e1[20], e2[20], num;
float c1[20], c2[20], res[2020];

int main()
{
    memset(res, 0, sizeof(res));
    cin >> K1;
    for(int i = 0; i < K1; i++)
        cin >> e1[i] >> c1[i];

    cin >> K2;
    for(int i = 0; i < K2; i++)
        cin >> e2[i] >> c2[i];

    for(int i = 0; i < K1; i++){
        for(int j = 0; j < K2; j++){
            //cout << e1[i] + e2[j] << " " << c1[i] * c2[j] << endl;
            res[e1[i] + e2[j]] += c1[i] * c2[j];
        }
    }

    num = 0;
    for(int i = 0; i < 2020; i++){
        //cout << res[i] << endl;
        if(res[i] != 0.0)
            num++;
    }

    cout << num;
    for(int i = 2000; i >= 0; i--){
        if(res[i] != 0.0)
            printf(" %d %.1f", i, res[i]);
            //cout << " " << i << " " << res[i];
    }

    return 0;
}
