#include <iostream>

using namespace std;

int n;
int num[20][20];

int main()
{
    cin >> n;
    int x = 1;
    for(int i = 0; i < n * n - 1; i++){
        for(int j = i; j >= 0; j--){
            if(j < n && i - j < n){ //���Ʊ���ѭ����Ԫ����Ŀ(i-j, j)���ϵ㣬(j, i-j)���µ�
                if(i % 2 != 0)
                    num[i-j][j] = x++;
                else
                    num[j][i-j] = x++;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            cout << num[i][j] << " ";
        }
        cout << num[i][n-1] << endl;
    }

    return 0;
}
