#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
int maxL, res[110], N, M, ID, K, LID;
vector<int> links[110];

void dfs(int index, int level){
    if(links[index].size() == 0){
        maxL = max(maxL, level);
        res[level]++;
        return;
    }

    for(int i = 0; i < links[index].size(); i++)
        dfs(links[index][i], level+1);
}

int main(){
    scanf("%d %d", &N, &M);
    for(int j = 0; j < M; j++){
        scanf("%d %d", &ID, &K);
        for(int i = 0; i < K; i++){
            scanf("%d", &LID);
            links[ID].push_back(LID);
        }
    }

    dfs(1, 0);

    for(int i = 0; i < maxL; i++)
        printf("%d ", res[i]);
    printf("%d", res[maxL]);

    return 0;
}
