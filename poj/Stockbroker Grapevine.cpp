#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 0x3f3f3f3f;
int N;
int w[150][150];

void floyd(){
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(w[i][j] > w[i][k] + w[k][j])
                    w[i][j] = w[i][k] + w[k][j];
            }
        }
    }
}

int main()
{
    cin >> N;
    while(N != 0){
        memset(w, MAX, sizeof(w));
        for(int i = 1; i <= N; i++){
            int n;
            cin >> n;
            for(int j = 1; j <= n; j++){
                int s, t;
                cin >> s >> t;
                w[i][s] = t;
            }
            w[i][i] = 0;
        }

        floyd();

        int start = -1;
        int res = MAX;
        for(int i = 1; i <= N; i++){
            int maxt = -1;
            for(int j = 1; j <= N; j++){
                if(w[i][j] > maxt)
                    maxt = w[i][j];
            }
            if(maxt < res){
                res = maxt;
                start = i;
            }
        }

        if(start != -1)
            cout << start << " " << res << endl;
        else
            cout << "disjoint" << endl;
        cin >> N;
    }
    //cout << "Hello world!" << endl;
    return 0;
}
