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
    int res;

    int maxDepth(Node* root) {
        res = 0;
        if(root != NULL)
            traverse(root, 0);
        return res;
    }

    void traverse(Node* root, int val){
        if(root->children.empty()){
            res = max(res, val+1);
            return;
        }
        val++;
        for(Node* node: root->children)
            traverse(node, val);
    }
};