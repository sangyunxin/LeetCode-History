#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

struct STU{
    string id;
    int inH, inM, inS, outH, outM, outS;
};

bool in(STU & a, STU & b){
    if(a.inH != b.inH)
        return a.inH < b.inH;
    else if(a.inM != b.inM)
        return a.inM < b.inM;
    else if(a.inS != b.inS)
        return a.inS < b.inS;
}

bool out(STU & a, STU & b){
    if(a.outH != b.outH)
        return a.outH > b.outH;
    else if(a.outM != b.outM)
        return a.outM > b.outM;
    else if(a.outS != b.outS)
        return a.outS > b.outS;
}

vector<STU> stu;
string ID;
int M, inH, inM, inS, outH, outM, outS;

int main()
{
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> ID;
        scanf("%d:%d:%d %d:%d:%d", &inH, &inM, &inS, &outH, &outM, &outS);
        STU c = {ID, inH, inM, inS, outH, outM, outS};
        stu.push_back(c);
    }

    sort(stu.begin(), stu.end(), in);
    cout << stu[0].id << " ";
    sort(stu.begin(), stu.end(), out);
    cout << stu[0].id << endl;

    return 0;
}
