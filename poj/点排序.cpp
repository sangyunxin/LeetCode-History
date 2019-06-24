#include <iostream>
#include <algorithm>

using namespace std;

int sx, sy, n;

struct Node{
    int x, y;
} nodes[110];


bool cmp(const Node & a, const Node & b){
    int dista = (a.x - sx) * (a.x - sx) + (a.y - sy) * (a.y - sy);
    int distb = (b.x - sx) * (b.x - sx) + (b.y - sy) * (b.y - sy);
    if(dista != distb)
        return dista < distb;
    else
        return a.x < b.x;

}



int main() {
    cin >> sx >> sy;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nodes[i].x >> nodes[i].y;
    }
    sort(nodes, nodes+n, cmp);
    int i = 0;
    for(; i < n - 1; i++){
        cout << "("  << nodes[i].x << "," << nodes[i].y << "), ";
    }

    cout << "(" << nodes[i].x << "," << nodes[i].y << ")" << endl ;
    return 0;
}
