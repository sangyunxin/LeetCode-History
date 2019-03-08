class Solution {
public:
    string longestPalindrome(string s) {
        /*
		 * 1. 当i在max_right左边时，其对应位置的点j为(2*pos-i)。有两种情况：
		 *    a. 当j点的回文串长度较短时(dp[j] <= max_right-pos), 这时i位置的基础回文串长度为dp[j]，之后向左右扩展寻找更大长度
		 *    b. 当j点的回文串长度较长时(dp[j] > max_right-pos), 这时i位置的基础回文串长度为max_right-pos，之后向左右扩展寻找
		 * 2. 当i在max_right右边时，说明暂未有对应值。直接向左右扩展寻找
		 */

		string cs = "#";

		for (int i = 0; i < s.length(); i++) {
			cs += s[i];
			cs += "#";
		}

		//cout << cs << endl;

		int n = cs.length(), max_right = 0, pos = 0, start = -1;

		vector<int> dp(n, 1);

		for (int i = 0; i < n; i++) {
			if (i < max_right)
				start = min(dp[2 * pos - i], max_right - i) + i;
			else
				start = i + 1;

			while (2 * i - start >= 0 && start < n && cs[2 * i - start] == cs[start]) {
				start++;
			}

			dp[i] = start - i;
			if (dp[i] >= max_right - pos + 1) {
				max_right = start;
				pos = i;
			}
		}

		string res = "";
		if (cs[pos] != '#')
			res += cs[pos];

		for (int i = pos + 1; i < max_right; i++) {
			if (cs[i] != '#')
				res = cs[i] + res + cs[i];
		}
		//cout << res << endl;
		return res;

    }
};