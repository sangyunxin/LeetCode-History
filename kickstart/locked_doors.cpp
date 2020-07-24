#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

vector<int> path, D, Y;
int N, Q;
unordered_map<string, vector<int>> query_idx;
unordered_map<int, set<int>> query_ends;

void helper(int S, int K, int c, int l, int r, int k){
    if(query_ends[S].count(k) == 1) {
        string key = to_string(S) + "," + to_string(k);
        for(int idx: query_idx[key]) {
            Y[idx] = c;
        }
        query_ends[S].erase(k);
    }

    if(k == K) return;

    if(l == -1) {
        for(int nk: query_ends[S]){
            string key = to_string(S) + "," + to_string(nk);
            for(int idx: query_idx[key])
                Y[idx] = r + (nk - k) + 1;
        }
        return;
    }

    if(r == N - 1) {
        for(int nk: query_ends[S]){
            string key = to_string(S) + "," + to_string(nk);
            for(int idx: query_idx[key])
                Y[idx] = l - (nk - k) + 2;
        }
        return;
    }

    if(D[l] <= D[r])
        helper(S, K, l+1, l-1, r, k+1);
    else
        helper(S, K, r+2, l, r+1, k+1);

}


int main() {
    int T, tmp;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        cin >> N >> Q;
        D.clear();
        for(int i = 0; i < N - 1; ++i){
            cin >> tmp;
            D.push_back(tmp);
        }

        query_ends.clear();
        query_idx.clear();
        Y.clear();
        Y.resize(Q);

        for(int idx = 0; idx < Q; ++idx) {
            int S, K;
            cin >> S >> K;
            string key = to_string(S) + "," + to_string(K);
            query_idx[key].push_back(idx);
            query_ends[S].insert(K);
        }

        for(auto it = query_ends.begin(); it != query_ends.end(); ++it) {
            int S = it->first, K = *it->second.rbegin();
            cout << K << endl;
            helper(S, K, S, S-2, S-1, 1);
        }

        cout << "Case #" << t << ": ";
        for_each(Y.begin(), Y.end(), [](const auto &i){cout << i << " "; });
        cout << endl;
    }

    return 0;
}