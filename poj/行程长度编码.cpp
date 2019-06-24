#include <iostream>
#include <cstring>

using namespace std;

char s[1050];

int main()
{
    cin >> s;
    strupr(s);
    char cur = s[0];
    int num = 1;
    for(int i = 1; i < strlen(s); i++){
        if(cur != s[i]){
            cout << "(" << cur << "," << num << ")";
            num = 0;
            cur = s[i];
        }

        num++;
    }

    cout << "(" << cur << "," << num << ")" << endl;
    return 0;
}
