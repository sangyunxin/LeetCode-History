#include <iostream>

using namespace std;

int num[200][200];
int result[10010];
int c = 1;
int n;

int main()
{
    for(int i = 1; i <= 200 && c <= 10000; i++){
        for(int j = 1; j <= i; j++){
            result[c] = result[c-1] + i;
            c++;
        }
    }

    cin >> n;
    while(n != 0){
        cout << n << " " << result[n] << endl;
        cin >> n;
    }
    return 0;
}
