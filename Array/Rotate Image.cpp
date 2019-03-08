class Solution {
public:
    // 一次变换
    int swap(vector<vector<int>>& matrix, int num, int next_i, int next_j){
        int tmp = matrix[next_i][next_j];
        matrix[next_i][next_j] = num;
        return tmp;
    }
    
    // 一轮变换
    void round(vector<vector<int>>& matrix, int n, int i, int j){
        //printf("%d, %d\n", i, j);
        int num = matrix[i][j], next_i = i, next_j = j, tmp = next_i;

        for(int i = 0; i < 4; i++){
            tmp = next_i;
            next_i = next_j;
            next_j = n - tmp - 1;
            num = swap(matrix, num, next_i, next_j);
            //printf("%d, %d\n", next_i, next_j);
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int next_i, next_j, tmp;
        
        for(int i = 0; i < n / 2; i++){
            for(int j = i; j < n - i - 1 ; j++){
                round(matrix, n, i, j);
                //printf("\n");
            }
        }
    }
};