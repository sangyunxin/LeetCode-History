#include <iostream>
#include <cstdio>

using namespace std;
int A[6], p, num[6], cur, N;

int main()
{
    p = 1;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> cur;
        if(cur % 5 == 0 && cur % 2 == 0){
            A[1] += cur;
            num[1]++;
        }
        else if(cur % 5 == 1){
            A[2] += p * cur;
            p *= -1;
            num[2]++;
        }
        else if(cur % 5 == 2){
            A[3]++;
            num[3]++;
        }
        else if(cur % 5 == 3){
            A[4] += cur;
            num[4]++;
        }
        else if(cur % 5 == 4 && cur > A[5]){
            A[5] = cur;
            num[5]++;
        }
    }

    for(int i = 1; i < 4; i++){
        if(num[i] == 0)
            printf("N ");
        else
            printf("%d ", A[i]);
    }

    //cout << "A4" << A[4] << endl;
    if(num[4] != 0)
        printf("%.1f ", (double)A[4]/num[4]);
    else
        printf("N ");

    if(num[5] != 0)
        printf("%d\n", A[5]);
    else
        printf("N\n");

    return 0;
}
