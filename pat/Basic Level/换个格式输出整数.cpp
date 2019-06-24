#include <iostream>

using namespace std;

int b, s, n, num;

int main()
{
    cin >> num;
    b = num / 100;
    num %= 100;
    s = num / 10;
    n = num % 10;

    for(int i = 0; i < b; i++)
        cout << "B";
    for(int i = 0; i < s; i++)
        cout << "S";
    for(int i = 1; i <= n; i++)
        cout << i;
    cout << endl;
    //cout << "Hello world!" << endl;
    return 0;
}
