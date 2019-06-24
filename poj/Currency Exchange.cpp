#include <iostream>
#include <cstring>

using namespace std;

int N, M, S, NN;
double V;

struct Node{
    int A, B;
    double r, c;
} nodes[250];

double dist[150];

bool relax(){
    bool flag = false;
    for(int i = 0; i < NN; i++){
        if(dist[nodes[i].B] < (dist[nodes[i].A] - nodes[i].c) * nodes[i].r){
            dist[nodes[i].B] = (dist[nodes[i].A] - nodes[i].c) * nodes[i].r;
            flag = true;
        }
    }
    return flag;
}

bool bellmanford(){
    bool flag;
    for(int i = 0; i < N; i++){
        flag = relax();
        if(!flag)
            return false;
    }
    return flag;
}

int main()
{
    memset(dist, 0, sizeof(dist));
    cin >> N >> M >> S >> V;
    dist[S] = V;
    NN = 0;
    for(int i = 0; i < M; i++){
        int A, B;
        double Rab, Cab, Rba, Cba;
        cin >> A >> B >> Rab >> Cab >> Rba >> Cba;
        nodes[NN].A = A;
        nodes[NN].B = B;
        nodes[NN].c = Cab;
        nodes[NN++].r = Rab;
        nodes[NN].A = B;
        nodes[NN].B = A;
        nodes[NN].c = Cba;
        nodes[NN++].r = Rba;
    }

    if(bellmanford())
        cout << "YES" <<endl;
    else
        cout << "NO" << endl;

    return 0;
}
