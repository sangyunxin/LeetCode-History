#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int n, x[210], y[210];
double dist[210][210];

void floyd(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
}

int main(){
    cin >> n;
    int k = 0;
    while(n != 0){
        k++;
        memset(dist, 0, sizeof(dist));
        for(int i = 1; i <= n; i++){
            cin >> x[i] >> y[i];
        }

        for(int i = 1; i < n; i++)
            for(int j = i+1; j <= n; j++)
                dist[i][j] = dist[j][i] = sqrt((x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]));

        floyd();
        printf("Scenario #%d\n", k);
        printf("Frog Distance = %.3f\n\n", dist[1][2]);
        cin >> n;
    }
    return 0;
}
