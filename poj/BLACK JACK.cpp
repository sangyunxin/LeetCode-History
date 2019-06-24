#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int me[15], you[15];

bool isBlackJacks(int card[], int k){
    if(k == 2){
        if(card[0] == -1 && card[1] == 10)
            return true;
        if(card[1] == -1 && card[0] == 10)
            return true;
    }

    return false;
}

int getNum(int card[], int k){
    if(isBlackJacks(card, k))
        return 0;

    int total = 0;
    int a = 0;
    for(int i = 0; i < k; i++){
        if(card[i] != -1)
            total += card[i];
        else
            a++;
    }

    for(int i = 0; i < a; i++){
        if(total + 11 > 21)
            total++;
        else
            total += 11;
    }

    return total;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        char c[3];
        cin >> c;
        if(c[0] == 'J' || c[0] == 'Q' || c[0] == 'K' || strcmp(c, "10") == 0)
            me[i] = 10;
        else if(c[0] == 'A')
            me[i] = -1;
        else
            me[i] = c[0] - '0';
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        char c[3];
        cin >> c;
        if(c[0] == 'J' || c[0] == 'Q' || c[0] == 'K' || strcmp(c, "10") == 0)
            you[i] = 10;
        else if(c[0] == 'A')
            you[i] = -1;
        else
            you[i] = c[0] - '0';

        cout << you[i] << endl;
    }

    int myCard = getNum(me, n);
    int youCard = getNum(you, m);
//    cout << myCard << endl;
//    cout << youCard << endl;

    if(myCard == youCard)
        cout << "draw";
    else if(myCard == 0)
        cout << "win";
    else if(youCard == 0)
        cout << "lose";
    else if(myCard == 21)
        cout << "win";
    else if(youCard == 21)
        cout << "lose";
    else if(myCard < 21 && youCard > 21)
        cout << "win";
    else if(myCard > 21 && youCard < 21)
        cout << "lose";
    else if(myCard > youCard)
        cout << "win";
    else
        cout << "lose";

    cout << endl;

//    for(int i = 0; i < 20; i++){
//        cin >> n;
//    }

    //system("pause");
    return 0;
}
