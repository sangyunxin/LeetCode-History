#include <iostream>
#include <cstdio>

using namespace std;

float res, p[5][5], maxp[5];

int main()
{
    for(int i = 0; i < 3; i++){
        int index = -1;
        float tmp = -1;
        for(int j = 0; j < 3; j++){
            cin >> p[i][j];
            if(p[i][j] > tmp){
                tmp = p[i][j];
                index = j;
            }
        }

        if(index == 0)
            cout << "W ";
        else if(index == 1)
            cout << "T ";
        else
            cout << "L ";

        maxp[i] = tmp;
    }

    res = (maxp[0] * maxp[1] * maxp[2] * 0.65 - 1) * 2;
    printf("%.2f\n", res);
    return 0;
}
