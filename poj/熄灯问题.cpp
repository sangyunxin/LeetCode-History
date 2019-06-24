#include <iostream>

using namespace std;

int puzzle[6][8], press[6][8];

bool guess(){
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 6; j++){
            press[i+1][j] = (puzzle[i][j] + press[i-1][j] + press[i][j-1] + press[i][j+1] + press[i][j]) % 2;
        }
    }

    bool flag = true;
    for(int j = 1; j <= 6; j++){
        if((press[5][j] + puzzle[5][j] + press[4][j] + press[5][j-1] + press[5][j+1]) % 2 != 0){
            flag = false;
            break;
        }
    }

    return flag;
}

void enumate(){
    for(int i = 1; i <= 6; i++){
        press[1][i] = 0;
    }

    while(!guess()){
        int c = 1;
        press[1][c]++;
        while(press[1][c] > 1){
            press[1][c] = 0;
            c++;
            press[1][c]++;
        }
    }

    return;
}

int main()
{
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 6; j++){
            cin >> puzzle[i][j];
        }
    }

    enumate();

    for(int i = 1; i <= 5; i++){
        for(int j = 1; j < 6; j++){
            cout << press[i][j] << " ";
        }
        cout << press[i][6] << endl;
    }
    return 0;
}
