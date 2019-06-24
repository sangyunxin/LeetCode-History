#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

const int MAX = 0x3f3f3f3f;

int puzzle[6][6], press[6][6];
int res, cur;

bool success(){
    int target = (puzzle[1][1] + press[1][1] + press[2][1] + press[1][2]) % 2;
    for(int r = 1; r <= 4; r++){
        for(int c = 1; c <= 4; c++){
            if((puzzle[r][c] + press[r-1][c] + press[r][c] + press[r+1][c] + press[r][c-1] + press[r][c+1]) % 2 != target){
                return false;
            }
        }
    }

    return true;
}


bool enumate(){
    bool flag = false;
    for(int i = 0; i < pow(2, 16); i++){
        bitset<16> b(i);
        cur = 0;
        int k = 0;
        for(int r = 1; r <= 4; r++){
            for(int c = 1; c <= 4; c++){
                cur += b[k];
                press[r][c] = b[k++];
            }

        }

        if(success() && res > cur){
            res = cur;
            flag = true;
        }
    }

    return flag;
}

int main(){
    res = MAX;
    for(int r = 1; r <= 4; r++){
        for(int c = 1; c <= 4; c++){
            char x;
            cin >> x;
            puzzle[r][c] = x == 'b' ? 1: 0;
        }
    }

    if(enumate())
        cout << res << endl;
    else
        cout << "Impossible" << endl;

    return 0;
}
