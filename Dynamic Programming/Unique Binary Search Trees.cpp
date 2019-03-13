class Solution {
public:
    /*
    * 规定G(n)为长度为n的平衡二叉树的数量
    * 规定F(i, n)为长度为n时，以i节点为根节点的二叉树数量
    * 易知：G(n) = F(1, n) + ... + F(n, n)
    * 而F(i, n) = 左子树的数量×右子树的数量
    * F(i, n) = G(i-1)G(n-i)
    * 展开: G(n) = G(0)G(n-1) + ... + G(n-1)G(0)
    */

    int numTrees(int n) {
        vector<int> G(n+1, 0);
        G[0] = G[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++)
                G[i] += G[j] * G[i-j-1];
        }

        return G[n];

    }
};