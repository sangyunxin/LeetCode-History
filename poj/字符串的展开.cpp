#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int p1, p2, p3;
char s[110];
vector<char> res;

int main()
{
    cin >> p1 >> p2 >> p3;
    cin >> s;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] != '-')
            res.push_back(s[i]);
        else{
            if(i >= strlen(s) - 1 || i == 0 || s[i+1] <= s[i-1]){
                res.push_back(s[i]);
                continue;
            }

            if(s[i+1] == s[i-1] + 1)
                continue;

            if(isdigit(s[i-1]) && isalpha(s[i+1])){
                res.push_back(s[i]);
                continue;
            }

            if(isdigit(s[i+1]) && isalpha(s[i-1])){
                res.push_back(s[i]);
                continue;
            }

            if(isdigit(s[i+1]) && p1 != 3){
                if(p3 == 1){
                    for(char c = s[i-1] + 1; c < s[i+1]; c++){
                        for(int k = 0; k < p2; k++)
                            res.push_back(c);
                    }
                }else if(p3 == 2){
                    for(char c = s[i+1] - 1; c > s[i-1]; c--){
                        for(int k = 0; k < p2; k++)
                            res.push_back(c);
                    }
                }
            }else if(p1 == 1){
                if(p3 == 1){
                    for(char c = s[i-1] + 1; c < s[i+1]; c++){
                        for(int k = 0; k < p2; k++)
                            res.push_back(c);
                    }
                }else if(p3 == 2){
                    for(char c = s[i+1] - 1; c > s[i-1]; c--){
                        for(int k = 0; k < p2; k++)
                            res.push_back(c);
                    }
                }
            }else if(p1 == 2){
                char ss = 'A' + s[i-1] - 'a';
                char es = 'A' + s[i+1] - 'a';
                if(p3 == 1){
                    for(char c = ss + 1; c < es; c++){
                        for(int k = 0; k < p2; k++)
                            res.push_back(c);
                    }
                }else if(p3 == 2){
                    for(char c = es - 1; c > ss; c--){
                        for(int k = 0; k < p2; k++)
                            res.push_back(c);
                    }
                }
            }else if(p1 == 3){
                for(char c = s[i-1] + 1; c < s[i+1]; c++){
                        for(int k = 0; k < p2; k++)
                            res.push_back('*');
                }
            }
        }
    }

    for(int i = 0; i < res.size(); i++){
        cout << res[i];
    }
    cout << endl;
    return 0;
}
