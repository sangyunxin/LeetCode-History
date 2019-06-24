#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    double N;

    cin >> N;
    double res = 0;

    if(N >= 0 && N < 5)
        res = -1 * N + 2.5;
    else if(N >= 5 && N < 10)
        res = 2 - 1.5 * (N - 3) * (N - 3);
    else
        res = N / 2 - 1.5;

    printf("%.3f\n", res);
    return 0;
}
