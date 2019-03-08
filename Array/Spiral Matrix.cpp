class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        
        int m = matrix.size(), n = matrix[0].size();
        int u = 0, d = m - 1, l = 0, r = n - 1, k = 0;
        
        while(true){
            // left -> right
            for(int col = l; col <= r; col++)
                res.push_back(matrix[u][col]);
            if(++u > d) break;
            
            // up -> down
            for(int row = u; row <= d; row++)
                res.push_back(matrix[row][r]);
            if(--r < l) break;
            
            // right -> left
            for(int col = r; col >= l; col--)
                res.push_back(matrix[d][col]);
            if(--d < u) break;
            
            // down -> up
            for(int row = d; row >= u; row--)
                res.push_back(matrix[row][l]);
            if(++l > r) break;
        }
        
        return res;
    }
};