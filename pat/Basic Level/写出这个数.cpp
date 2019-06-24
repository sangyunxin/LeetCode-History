#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char m[][10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
char n[110], res[110];
int tmp;

int main()
{
    cin >> n;
    tmp = 0;
    for(int i = 0; i < strlen(n); i++){
        tmp += n[i] - '0';
    }

    sprintf(res, "%d", tmp);

    for(int i = 0; i < strlen(res) - 1; i++){
        cout << m[res[i] - '0'] << " ";
    }
    cout << m[res[strlen(res) - 1] - '0'] << endl;
    return 0;
}
