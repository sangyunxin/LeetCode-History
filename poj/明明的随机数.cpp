#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num[110];
vector<int> res;
int n;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> num[i];

    sort(num, num+n);

    int cur = num[0];
    res.push_back(cur);
    for(int i = 1; i < n; i++){
        if(num[i] != cur){
            cur = num[i];
            res.push_back(cur);
        }
    }

    cout << res.size() << endl;
    for(int i = 0; i < res.size()-1; i++)
        cout << res[i] << " ";
    cout << res[res.size()-1] << endl;
    return 0;
}
