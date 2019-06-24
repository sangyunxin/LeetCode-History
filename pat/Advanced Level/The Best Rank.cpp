#include <iostream>
#include <algorithm>

using namespace std;

string id;
int N, ML, ra, rc, rm, re, res;
float a, c, m, e;

struct STU{
    string id;
    float score;

    bool operator < (const STU & a) const{
        return score > a.score;
    }
} A[2010], C[2010], M[2010], E[2010];

int getr(STU s[2010], string id, char c){
    int r = 1;
    bool flag = false;

    int pre = s[0].score;
    for(int j = 0; j < N; j++){
        if(pre != s[j].score){
            r = j+1;
            pre = s[j].score;
        }

        if(s[j].id == id){
            flag = true;
            break;
        }
    }

    if(!flag){
        cout << "N/A" << endl;
        return -1;
    }

    if(r == 1){
        cout << r << " " << c << endl;
        return -1;
    }


    return r;
}

int main()
{
    cin >> N >> ML;
    for(int i = 0; i < N; i++){
        cin >> id >> c >> m >> e;
        a = (c + m + e) / 3;
        A[i] = {id, a};
        C[i] = {id, c};
        M[i] = {id, m};
        E[i] = {id, e};
    }
    sort(A, A+N);
    sort(C, C+N);
    sort(M, M+N);
    sort(E, E+N);

//    for(int i = 0; i < N; i++){
//        cout << A[i].id << " " << A[i].score << endl;
//    }


    for(int i = 0; i < ML; i++){
        cin >> id;
        ra = getr(A, id, 'A');
        if(ra == -1)
            continue;


        rc = getr(C, id, 'C');
        if(rc == -1)
            continue;

        rm = getr(M, id, 'M');
        if(rm == -1)
            continue;

        re = getr(E, id, 'E');
        if(re == -1)
            continue;

        if(ra <= rc && ra <= rm && ra <= re)
            cout << ra << " A" << endl;
        else if(rc < ra && rc <= rm && rc <= re)
            cout << rc << " C" << endl;
        else if(rm < ra && rm < rc && rm <= re)
            cout << rm << " M" << endl;
        else
            cout << re << " E" << endl;
    }

    //cout << "Hello world!" << endl;
    return 0;
}
