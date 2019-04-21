/*
// Definition for a Node.
class Node {
public:
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
    vector<int> preorder(Node* root) {
        vector<int> values;
        preOrder(root, values);
        return values;
    }

    void preOrder(Node* root, vector<int>& values){
        if(root == NULL)
            return;
        values.push_back(root->val);
        for(Node* node: root->children){
            preOrder(node, values);
        }
    }
};