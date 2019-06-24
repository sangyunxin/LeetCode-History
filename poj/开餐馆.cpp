#include <iostream>
#include <cstring>

using namespace std;

int T, n, k;
int m[110], p[110], maxP[110];

void dp(){
    for(int i = 0; i <= n; i++){
        maxP[i] = p[i];
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= n - 1 && m[i] - m[j] > k; j++){
            if(maxP[i] < maxP[j] + p[i])
                maxP[i] = maxP[j] + p[i];
        }
    }
}

int main()
{
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> m[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> p[i];
        }

        dp();
        int max = 0;
        for(int i = 1; i <= n; i++){
            if(max < maxP[i])
                max = maxP[i];
        }
        cout << max << endl;
    }

    return 0;
}
