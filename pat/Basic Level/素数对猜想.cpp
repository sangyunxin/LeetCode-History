#include <iostream>

using namespace std;

int N, pre, cur, res;

bool isPrime(int num){
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    cin >> N;

    pre = 2;
    for(int i = 2; i <= N; i++){
        if(isPrime(i)){
            if(i - pre == 2)
                res++;
            pre = i;
        }
    }

    cout << res << endl;
    return 0;
}
