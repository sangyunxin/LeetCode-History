#include <iostream>
#include <string>

using namespace std;
string s;
char matrix[25][25];
int r, c;

int main()
{
    cin >> c;
    cin >> s;
    r = s.size() / c;

    //cout << c << endl;

    for(int i = 0; i < s.size(); i++){
        if((i/c) % 2 == 0)
            matrix[i/c][i%c] = s[i];
        else
            matrix[i/c][c-1-(i%c)] = s[i];
    }

    for(int j = 0; j < c; j++){
        for(int i = 0; i < r; i++)
            cout << matrix[i][j];
    }

    cout << endl;
    return 0;
}
