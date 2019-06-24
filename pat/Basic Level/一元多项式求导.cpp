#include <iostream>
#include <vector>

using namespace std;
vector<int> resp, resn;
int tmpp, tmpn, i;

int main()
{
    while(cin >> tmpp >> tmpn){
        if(tmpn == 0)
            break;
        resp.push_back(tmpp * tmpn);
        resn.push_back(tmpn - 1);
    }

    if(resp.size() > 0){
        for(i = 0; i < resp.size() - 1; i++)
            cout << resp[i] << " " << resn[i] << " ";
        cout << resp[i] << " " << resn[i] << endl;
    }else
        cout << "0 0" << endl;

    //cout << "Hello world!" << endl;
    return 0;
}
