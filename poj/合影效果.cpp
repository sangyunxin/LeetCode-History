#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

double f[45], m[45];
int N, F, M;

int main()
{
    F = 0;
    M = 0;
    cin >> N;

    for(int i = 0; i < N; i++){
        char sex[10];
        cin >> sex;
        if(sex[0] == 'f')
            cin >> f[F++];
        else
            cin >> m[M++];
    }

    //cout << F << " " << M;

    sort(f, f+F);
    sort(m, m+M);

    for(int i = 0; i < M; i++)
        printf("%.2f ", m[i]);

    for(int i = F - 1; i > 0; i--)
        printf("%.2f ", f[i]);

    printf("%.2f \n", f[0]);
    return 0;
}
