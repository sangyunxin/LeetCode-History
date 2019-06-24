/*
// Definition for a Node.
class Node {
public:N-ary Tree Postorder Traversal
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> vals;
        postOrder(root, vals);
        return vals;
    }

    void postOrder(Node* root, vector<int>& vals){
        if(root == NULL)
            return;
        for(Node* node: root->children)
            postOrder(node, vals);
        vals.push_back(root->val);
    }
};