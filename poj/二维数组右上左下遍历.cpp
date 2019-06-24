#include <iostream>

using namespace std;

int r, c, a[110][110];

int main()
{
    cin >> r >> c;

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> a[i][j];

    for(int i = 0; i < r + c - 1; i++){
        for(int j = 0; j < r && j <= i; j++){
            if(i-j >= 0 && i-j < c)
                cout << a[j][i-j] << endl;
        }
    }

    //cout << "Hello world!" << endl;
    return 0;
}
