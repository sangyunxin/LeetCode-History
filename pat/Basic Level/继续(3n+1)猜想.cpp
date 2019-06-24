#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, cur, num[110], vis[11000];
vector<int> res;

int main()
{
    cin >> K;

    for(int i = 0; i < K; i++)
        cin >> num[i];

    for(int i = 0; i < K; i++){
        cur = num[i];

        if(vis[cur] == 1)
            continue;

        while(cur != 1){
            if(cur % 2 == 0)
                cur /= 2;
            else
                cur = (cur * 3 + 1) / 2;

            if(vis[cur] == 1)
                break;

            vis[cur] = 1;
        }
    }

    for(int i = K-1; i >= 0; i--)
        if(vis[num[i]] == 0)
            res.push_back(num[i]);

    sort(res.begin(), res.end());
    for(int i = res.size()-1; i > 0; i--)
        cout << res[i] << " ";
    cout << res[0] << endl;

    return 0;
}
