#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;
vector<string> res;
string s, tmp;

int main()
{
    getline(cin, s);
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            res.push_back(tmp);
            tmp = "";
        }else{
            tmp += s[i];
        }
    }
    res.push_back(tmp);

    for(int i = res.size() - 1; i > 0; i--)
        cout << res[i] << " ";
    cout << res[0] << endl;
    return 0;
}
