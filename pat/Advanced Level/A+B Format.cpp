#include <iostream>
#include <strstream>
#include <string>

using namespace std;

int a, b, res;
string s;

int main()
{
    cin >> a >> b;
    res = a+b;
    strstream ss;
    if(res < 0){
        res *= -1;
        cout << "-";
    }

    ss << res;
    ss >> s;
    ss.clear();

    for(int i = 0; i < s.size() - 1; i++){
        if(i % 3 == 0 && i != 0){
            cout << ",";
        }
        cout << s[i];
    }

    cout << s[s.size() - 1] << endl;

    return 0;
}
