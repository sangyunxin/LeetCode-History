#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector< vector<int> > edge;
map<int, bool> vis;
map<int, int> ru;
vector<int> res;

int v, a;

int finds(){
    int start = -1;
    for(int i = 1; i <= v; i++){
        if(ru[i] == 0 && !vis[i]){
            start = i;
            break;
        }
    }
    return start;
}

int main()
{
    cin >> v >> a;
    edge.resize(v+1);
    for(int i = 1; i <= v; i++){
        vis[i] = false;
        ru[i] = 0;
    }

    for(int i = 0; i < a; i++){
        int s, d;
        cin >> s >> d;
        edge[s].push_back(d);
        ru[d]++;
    }

    int start = finds();

    while(start != -1){
        res.push_back(start);
        vis[start] = true;
        for(int i = 0; i < edge[start].size(); i++){
            ru[edge[start][i]]--;
        }

        start = finds();
    }

    for(int i = 0; i < res.size() - 1; i++){
        cout << "v" << res[i] << " ";
    }
    cout << "v" << res[res.size() - 1] << endl;
    return 0;
}
