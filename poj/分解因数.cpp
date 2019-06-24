#include <iostream>
#include <vector>

using namespace std;

int res;

void bt(int a, int s){
    if(a == 1){
        res++;
        return;
    }

    if(a < 1)
        return;

    for(int i = s; i <= a; i++){
        if(a % i == 0)
            bt(a/i, i);
    }
}


int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        res = 0;
        bt(num, 2);
        cout << res << endl;
    }
    // << "Hello world!" << endl;
    return 0;
}
