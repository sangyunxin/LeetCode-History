#include <iostream>

using namespace std;

int num[150][150];
int m, n;

int main()
{
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> num[i][j];
        }
    }

    for(int j = 0; j < n; j++){
        for(int i = 0; i < m - 1; i++){
            cout << num[i][j] << " ";
        }
        cout << num[m-1][j] << endl;
    }
    return 0;
}
