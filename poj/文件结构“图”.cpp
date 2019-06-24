#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

priority_queue<string, vector<string>, greater<string> > q[1005];

int main()
{
    int n = 1;
    int k = 1;
    bool mark = true;
    string cur;
    cin >> cur;
    while(cur[0] != '#'){
        if(mark){
            cout << "DATA SET " << n << ":" << endl;
            cout << "ROOT" << endl;
            mark = false;
        }

        if(cur[0] == 'd'){
            for(int i = 0; i < k; i++)
                cout << "|     ";
            cout << cur << endl;
            k++;
        }else if(cur[0] == 'f'){
            q[k].push(cur);
        }else if(cur[0] == ']' || cur[0] == '*'){
            while(!q[k].empty()){
                for(int i = 0; i < k - 1; i++)
                    cout << "|     ";
                cout << q[k].top() << endl;
                q[k].pop();
            }
            k--;
        }

        if(cur[0] == '*'){
            mark = true;
            k = 1;
            n++;
            cout << endl;
        }

        cin >> cur;
    }
    return 0;
}
