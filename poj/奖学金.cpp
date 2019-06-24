#include <iostream>
#include <algorithm>

using namespace std;

struct STU{
    int i;
    int l, m, e;
    int total;

    bool operator <(const STU & a) const{
        if(total != a.total)
            return total > a.total;
        else if(l != a.l)
            return l > a.l;
        else
            return i < a.i;
    }
} students[350];

int n;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> students[i].l >> students[i].m >> students[i].e;
        students[i].i = i+1;
        students[i].total = students[i].l + students[i].m + students[i].e;
    }

    sort(students, students+n);
    for(int i = 0; i < 5; i++){
        cout << students[i].i+1 << " " << students[i].total << endl;
    }
    return 0;
}
