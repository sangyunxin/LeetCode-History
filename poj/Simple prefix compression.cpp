#include <iostream>
#include <string>

using namespace std;

string pre, cur;
int N, j, res;

int main(){
    cin >> N;
    res = 0;
    pre = "";
    for(int i = 0; i < N; i++){
        cin >> cur;
        j = 0;
        for(int k = 0; k < min(pre.size(), cur.size()); k++){
            if(pre[k] == cur[k])
                j++;
            else
                break;
        }
        res += cur.size() - j + 1;
        pre = cur;
    }

    cout << res - 1 << endl;
    return 0;
}
