#include <iostream>

using namespace std;

int m, n, no, num;

bool isPrime(int num){
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0)
            return false;
    }

    return true;
}

int main()
{
    cin >> m >> n;
    num = 2;
    no = 1;
    while(no < m){
        if(isPrime(num))
            no++;
        num++;
    }

    while(no <= n){
        if(isPrime(num)){
            no++;
            if((no - m) % 10 != 0 && no <= n)
                cout << num << " ";
            else
                cout << num << endl;
        }
        num++;
    }
    return 0;
}
