#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

string s1, s2;
int tag;
long long radix;

long long convert(string & s, long long radix){
    long long sum = 0;
    for(int i = 0; i < s.size(); i++){
        int num = isdigit(s[i]) ? s[i] - '0': 10 + s[i] - 'a';
        sum += num * pow(radix, s.size()-1-i);
    }

    return sum;
}

void findr(string & s1, string & s2, long long radix){
    long long low, high, mid, num2, tmp = 0, num1 = convert(s1, radix);

    for(int i = 0; i < s2.size(); i++){
        long long n = isdigit(s2[i]) ? s2[i] - '0': 10 + s2[i] - 'a';
        tmp = max(tmp, n);
    }

    low = tmp + 1;
    high = max(low, num1);

    //cout << num1 << " " << low << " " << high << endl;

    while(low <= high){
        mid = (low + high) / 2;
        num2 = convert(s2, mid);
        if(num2 > num1 || num2 < 0)
            high = mid - 1;
        else if(num2 < num1)
            low = mid + 1;
        else
            break;
    }

    if(num1 == num2)
        cout << mid << endl;
    else
        cout << "Impossible" << endl;
}

int main()
{
    cin >> s1 >> s2 >> tag >> radix;
    if(tag == 1)
        findr(s1, s2, radix);
    else
        findr(s2, s1, radix);
    return 0;
}
