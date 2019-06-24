#include <iostream>

using namespace std;

int num[3], N;

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++){
        int cur;
        cin >> cur;
        if(cur == 1)
            num[0]++;
        else if(cur == 5)
            num[1]++;
        else if(cur == 10)
            num[2]++;
    }

    for(int i = 0; i < 3; i++)
        cout << num[i] << endl;
    //cout << "Hello world!" << endl;
    return 0;
}
