#include <iostream>
#include <map>

using namespace std;

int N, yA, yB, pA, pB, sA, sB;
map<char, int> cA, cB;
char A, B, maxA, maxB;

int main()
{
    cin >> N;
    cA['C'] = cA['J'] = cA['B'] = 0;
    cB['C'] = cB['J'] = cB['B'] = 0;

    for(int i = 0; i < N; i++){
        cin >> A >> B;
        if(A == B){
            pA++;
            pB++;
        }else if((A == 'C' && B == 'J') || (A == 'J' && B == 'B') || (A == 'B' && B == 'C')){
            yA++;
            sB++;
            cA[A]++;
        }else{
            yB++;
            sA++;
            cB[B]++;
        }
    }
    cout << yA << " " << pA << " " << sA << endl;
    cout << yB << " " << pB << " " << sB << endl;

    if(cA['B'] >= cA['C'] && cA['B'] >= cA['J'])
        cout << "B ";
    else if(cA['C'] > cA['B'] && cA['C'] >= cA['J'])
        cout << "C ";
    else
        cout << "J ";

    if(cB['B'] >= cB['C'] && cB['B'] >= cB['J'])
        cout << "B" << endl;
    else if(cB['C'] > cB['B'] && cB['C'] >= cB['J'])
        cout << "C" << endl;
    else
        cout << "J" << endl;
    //cout << "Hello world!" << endl;
    return 0;
}
