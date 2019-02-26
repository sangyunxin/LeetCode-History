class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();
        if(matrix[0][0] > target || matrix[m-1][n-1] < target)	return false;
        
        int start = 0, end = m * n - 1;
        while(start <= end){
            int mid = (start + end) / 2;
            int row = mid / n;
            int col = mid % n;
            
            if(matrix[row][col] > target)
                end = mid - 1;
            else if(matrix[row][col] < target)
                start = mid + 1;
            else
                return true;
        } 
        return false;
    }
};