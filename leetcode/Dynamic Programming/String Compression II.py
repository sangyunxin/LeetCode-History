class Solution:
    def helper(self, cnt):
        if cnt >= 100:
            return 4
        if cnt >= 10:
            return 3
        if cnt > 1:
            return 2
        return cnt

    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        T = len(s) - k
        dp = [[float('inf') for _ in range(T+1)] for _ in range(len(s)+1)]
        dp[len(s)][T] = 0
        # dp[p][cnt] = min(helper(same) + dp[j+1][cnt+same]) for j in range(p+1, n)
        for p in range(len(s)-1, -1, -1):
            for cnt in range(T+1):
                same = 0
                for j in range(p, len(s)):
                    if s[j] == s[p]:
                        same += 1
                    if same + cnt > T:
                        break
                    dp[p][cnt] = min(dp[p][cnt], self.helper(same) + dp[j+1][cnt + same])
                dp[p][cnt] = min(dp[p][cnt], dp[p+1][cnt])

        return dp[0][0]