#include <iostream>

using namespace std;

int num;
char flag;

int main()
{
    cin >> num >> flag;
    int result = 8;
    if(num > 1000){
        result += ((num - 1000) / 500) * 4;
        num %= 500;
        if(num > 0)
            result += 4;
    }
    if(flag == 'y')
        result += 5;
    cout << result << endl;
    return 0;
}
