#include <iostream>

using namespace std;

int n, res;

int main()
{
    cin >> n;
    res = 0;
    while(n != 1){
        if(n % 2 == 0)
            n = n / 2;
        else
            n = (3 * n + 1) / 2;
        res++;
    }
    cout << res << endl;
    return 0;
}
