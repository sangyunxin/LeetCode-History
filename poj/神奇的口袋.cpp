#include <iostream>

using namespace std;

int n, a[25];
int res;

void bt(int w, int i){
    if(w == 40){
        res++;
        return;
    }

    if(i >= n)
        return;

    for(; i < n; i++){
        bt(w+a[i], i+1);
    }
}

int main()
{
    cin >> n;
    res = 0;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    bt(0, 0);
    cout << res << endl;
    return 0;
}
