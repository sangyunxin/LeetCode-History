#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct STU{
    int no, de, cai;

    bool operator<(const STU a) const{
        if(de + cai != a.de + a.cai)
            return de + cai > a.de + a.cai;
        else if(de != a.de)
            return de > a.de;
        else
            return no < a.no;
    }
} cur;

vector<STU> class1, class2, class3, class4;
int N, L, H, curd, curc;
string curn;

int main()
{
    cin >> N >> L >> H;
    for(int i = 0; i < N; i++){
        cin >> curn >> curd >> curc;
        if(curd < L || curc < L)
            continue;

        cur = {curn, curd, curc};
        if(curd >= H && curc >= H)
            class1.push_back(cur);
        else if(curd >= H)
            class2.push_back(cur);
        else if(curd < H && curc < H && curd >= curc)
            class3.push_back(cur);
        else
            class4.push_back(cur);
    }

    sort(class1.begin(), class1.end());
    sort(class2.begin(), class2.end());
    sort(class3.begin(), class3.end());
    sort(class4.begin(), class4.end());

    cout << class1.size() + class2.size() + class3.size() + class4.size() << endl;
    for(int i = 0; i < class1.size(); i++)
        cout << class1[i].no << " " << class1[i].de << " " << class1[i].cai << endl;
    for(int i = 0; i < class2.size(); i++)
        cout << class2[i].no << " " << class2[i].de << " " << class2[i].cai << endl;
    for(int i = 0; i < class3.size(); i++)
        cout << class3[i].no << " " << class3[i].de << " " << class3[i].cai << endl;
    for(int i = 0; i < class4.size(); i++)
        cout << class4[i].no << " " << class4[i].de << " " << class4[i].cai << endl;
    return 0;
}
