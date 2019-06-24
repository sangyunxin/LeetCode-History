#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

//可以使用贪心，对每一个不一样的数，按后面一个

struct Node{
    char s[35];
    int c = 0;

    bool operator<(const Node & b) const{
        return c > b.c;
    }
};

char sstr[35];
char estr[35];
char tmp[35];
priority_queue<Node> q;
vector<Node> vis;

char changChar(char c){
    if(c == '0')
        return '1';
    else
        return '0';
}

bool hasN(char s[35]){
    for(int i = 0; i < vis.size(); i++){
        if(strcmp(s, vis[i].s) == 0)
            return true;
    }

    return false;
}

void change(char s[35], int i){
    strcpy(tmp, s);
    tmp[i] = changChar(tmp[i]);
    if(i == 0){
        tmp[i+1] = changChar(tmp[i+1]);
    }else if(i == strlen(s) - 1){
        tmp[i-1] = changChar(tmp[i-1]);
    }else{
        tmp[i+1] = changChar(tmp[i+1]);
        tmp[i-1] = changChar(tmp[i-1]);
    }
}

int bfs(){
    while(!q.empty()){
        Node cur = q.top();
        q.pop();
        for(int i = 0; i < strlen(cur.s); i++){
            change(cur.s, i);
            if(!hasN(tmp)){
                if(strcmp(tmp, estr)){
                    return cur.c + 1;
                }
                Node n;
                strcpy(n.s, tmp);
                n.c = cur.c + 1;
                q.push(n);
                vis.push_back(n);
            }
        }
    }
    return -1;
}

int main()
{
    cin >> sstr >> estr;
    Node n;
    strcpy(n.s, sstr);
    n.c = 0;
    q.push(n);
    vis.push_back(n);
    int result = bfs();
    if(result == -1)
        cout << "impossible" << endl;
    else
        cout << result << endl;
    return 0;
}
