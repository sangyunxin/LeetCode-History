class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
	int k = 1, r = 0, c = 0, w = n;

	while (k <= n * n) {
		while (c <= w - 1) {
			res[r][c++] = k++;
		}
		r++;
		c--;

		while (r <= w - 1) {
			res[r++][c] = k++;
		}
		r--;
		c--;

		while (c >= n - w) {
			res[r][c--] = k++;
		}
		r--;
		c++;

		while (r > n - w) {
			res[r--][c] = k++;
		}
        r++;
		c++;

		w--;

	}

	return res;
    }
};