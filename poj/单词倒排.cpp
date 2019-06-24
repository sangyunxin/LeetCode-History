#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

char s[110];
vector<string> result;

int main()
{
    gets(s);
    char* tmpStr = strtok(s, " ");
    while(tmpStr != NULL){
        result.push_back(string(tmpStr));
        tmpStr = strtok(NULL, " ");
    }

    for(int i = result.size() - 1; i >= 1; i--){
        cout << result[i] << " ";
    }
    cout << result[0] << endl;
    return 0;
}
