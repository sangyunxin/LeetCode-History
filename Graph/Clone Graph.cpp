/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> copies;
        queue<Node*> q;
        copies[node] = new Node(node->val, {});
        q.push(node);

        while(!q.empty()){
            Node* cur = q.front();
            q.pop();

            for(Node* nb: cur->neighbors){
                if(copies.find(nb) == copies.end()){
                    copies[nb] = new Node(nb->val, {});
                    q.push(nb);
                }

                copies[cur]->neighbors.push_back(copies[nb]);
            }
        }

        return copies[node];
    }
};