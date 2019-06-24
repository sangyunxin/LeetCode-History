#include <iostream>
#include <string>

using namespace std;

struct Node{
    char val;
    Node * left;
    Node * right;

    Node(char c): val(c), left(NULL), right(NULL){};
};

string pre, mid;

Node* getTree(string & pre, string & mid){
    if(pre.size() == 0)
        return NULL;

    size_t pos = mid.find(pre[0]);
    string left = mid.substr(0, pos);
    string right = mid.substr(pos+1);
    string lpre = pre.substr(1, left.size());
    string rpre = pre.substr(1+left.size());

    Node *r = new Node(pre[0]);
    r->left = getTree(lpre, left);
    r->right = getTree(rpre, right);
    return r;
}

void aftRev(Node *root){
    if(root == NULL)
        return;
    aftRev(root->left);
    aftRev(root->right);
    cout << root->val;
}

int main()
{
    while(cin >> pre >> mid){
        cout << pre.size() << endl;
        Node * root = getTree(pre, mid);
        aftRev(root);
        cout << endl;
    }
    return 0;
}
