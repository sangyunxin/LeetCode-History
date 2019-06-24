#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;
char s[210];
vector<char> res;

int main()
{
    gets(s);
    int n = 0;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == ' '){
            n++;
            if(n == 1)
                cout << s[i];
        }else{
            n = 0;
            cout << s[i];
        }
    }

    cout << endl;
    return 0;
}
