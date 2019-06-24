#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct STU{
    string name, no;
    int score;

    bool operator <(const STU & a) const{
        return score < a.score;
    }
};

int main()
{
    vector<STU> students;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string cname, cno;
        int cscore;
        cin >> cname >> cno >> cscore;
        STU cstu = {cname, cno, cscore};
        students.push_back(cstu);
    }

    sort(students.begin(), students.end());
    cout << students[n-1].name << " " << students[n-1].no << endl;
    cout << students[0].name << " " << students[0].no << endl;
    return 0;
}
