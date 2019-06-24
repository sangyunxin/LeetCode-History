#include <iostream>

using namespace std;

string A, B;
char DA, DB;

int PA(string & A, char DA){
    int resA, nA;
    resA = nA = 0;

    for(int i = 0; i < A.size(); i++){
        if(A[i] == DA)
            nA++;
    }

    for(int i = 0; i < nA; i++){
        resA = resA * 10 + DA - '0';
    }

    return resA;
}

int main()
{
    cin >> A >> DA >> B >> DB;

    cout << PA(A, DA) + PA(B, DB) << endl;

    return 0;
}
