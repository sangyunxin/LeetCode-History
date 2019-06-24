#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
char s[550];

int findSpace(int n){
    for(int i = n + 1; i < strlen(s); i++)
        if(s[i] == ' ')
            return i;

    return -1;
}

int main()
{
    gets(s);
    int p = -1;
    int n = 0;

    while((n = findSpace(n)) != -1){
        for(int i = n - 1; i > p; i--)
            cout << s[i];
        cout << " ";
        p = n;
    }

    for(int i = strlen(s) - 1; i > p; i--)
        cout << s[i];

    cout << endl;

    return 0;
}
