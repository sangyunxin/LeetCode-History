#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

int sum;
char N[110], res[110];


int main()
{
    map<char, string> num;
    num['0'] = "zero";
    num['1'] = "one";
    num['2'] = "two";
    num['3'] = "three";
    num['4'] = "four";
    num['5'] = "five";
    num['6'] = "six";
    num['7'] = "seven";
    num['8'] = "eight";
    num['9'] = "nine";

    sum = 0;
    scanf("%s", &N);
    for(int i = 0; i < strlen(N); i++){
        sum += N[i] - '0';
    }

    sprintf(res, "%d", sum);
    //cout << res[0] << endl;

    for(int i = 0; i < strlen(res)-1; i++){
        cout << num[res[i]] << " ";
    }

    cout << num[res[strlen(res)-1]] << endl;

    return 0;
}
