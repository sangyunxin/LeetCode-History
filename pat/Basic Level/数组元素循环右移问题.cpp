#include <iostream>
#include <vector>

using namespace std;

int M, N, tmp;
vector<int> num;

int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        num.push_back(tmp);
    }

    for(int i = 0; i < N-1; i++){
        cout << num[(i+N*M-M)%N] << " ";
    }
    cout << num[(N-1+N*M-M)%N] << endl;
    return 0;
}
