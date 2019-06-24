#include <iostream>
#include <string>
#include <cstdio>
#include <strstream>
#include <algorithm>

using namespace std;

bool cmp(char & a, char & b){
    return a > b;
}

int num, a, b;
string cur;

int main()
{
    cin >> num;
    strstream ss;
    while(num != 0 && num != 6174){
        ss << num;
        ss >> cur;

        sort(cur.begin(), cur.end(), cmp);
        a = atoi(&cur[0]);

        sort(cur.begin(), cur.end());
        b = atoi(&cur[0]);
        printf("%04d - %04d = %04d\n", a, b, a-b);
        num = a - b;
    }

    return 0;
}
