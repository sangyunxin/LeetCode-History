#include <iostream>
#include <cstring>
#include <map>

using namespace std;

/*
  ֻ����һ��Pһ��T
  �м�ĩβ�Ϳ�ͷ����������A��
  ���Ǳ������㣺��ͷ��A�ĸ��� * �м��A�ĸ��� = ��β��A�ĸ���
*/

char s[110];
int n, p, t;
map<char, int> m;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        p = t = -1;
        m.clear();
        for(int j = 0; j < strlen(s); j++){
            m[s[j]]++;
            if(s[j] == 'P')
                p = j;
            if(s[j] == 'T')
                t = j;
        }

        if(m['P'] + m['A'] + m['T'] == strlen(s) && m['P'] == 1 && m['T'] == 1 && m['A'] > 0 && p * (t - p - 1) == strlen(s) - t - 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    //cout << "Hello world!" << endl;
    return 0;
}
