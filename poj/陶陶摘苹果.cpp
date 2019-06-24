#include <iostream>

using namespace std;

int res = 0;
int h[15], s;

int main()
{
    for(int i = 0; i < 10; i++)
        cin >> h[i];
    cin >> s;
    s += 30;
    for(int i = 0; i < 10; i++)
        if(h[i] <= s)
            res++;

    cout << res << endl;
    return 0;
}
