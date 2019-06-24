#include <iostream>
#include <string>

using namespace std;
string s1, s2, s3, s4;
string day[] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main()
{
    cin >> s1 >> s2 >> s3 >> s4;

    int i;
    for(i = 0; i < min(s1.size(), s2.size()); i++){
        if(s1[i] == s2[i] && isupper(s1[i]) && s1[i] <= 'G'){
            cout << day[s1[i] - 'A'] << " ";
            break;
        }
    }

    i++;
    for(; i < min(s1.size(), s2.size()); i++){
        if(s1[i] == s2[i]){
            if(s1[i] >= 'A' && s1[i] <= 'N'){
                cout << 10 + s1[i] - 'A' << ":";
                break;
            }
            else if(isdigit(s1[i])){
                cout << '0' << s1[i] << ":";
                break;
            }
        }
    }

    for(i = 0; i < min(s3.size(), s4.size()); i++){
        if(s3[i] == s4[i] && isalpha(s3[i])){
            if(i < 10)
                cout << '0' << i << endl;
            else
                cout << i << endl;
            break;
        }
    }

    return 0;
}
