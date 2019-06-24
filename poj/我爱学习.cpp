#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int n, m;
char keys[25][25];
char stc[25][120];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n ; i++){
        cin >> keys[i];
    }

    for(int i = 0; i <= m; i++){
        gets(stc[i]);
        cout << stc[i] << endl;
        for(int j = 0; j < n; j++){
            char * pos = strstr(stc[i], keys[j]);
            while(pos != NULL){
                for(int k = 0; k < strlen(keys[j]); k++){
                    *pos = '*';
                    pos++;
                }
                pos = strstr(stc[i], keys[j]);
            }
        }
    }

    for(int i = 0; i <= m; i++){
        cout << stc[i]  << endl;
    }

    return 0;
}
