def P(a0, a1, j_, j):
    if a0 > a1:
        if j_ <= j: return 1
        return 0
    else:
        if j_ >= j: return 1
        return 0

T = int(input())
for i in range(T):
    K = int(input())
    A = list(map(int, input().split()))
    A = [A[j] for j in range(K) if j == 0 or A[j] != A[j-1]]
    n = len(A)
    dp = [[0 for _ in range(4)] for _ in range(K)]
    for k in range(1, n):
        for j in range(4):
            dp[k][j] = float('inf')
            for j_ in range(4):
                dp[k][j] = min(dp[k-1][j_] + P(A[k-1], A[k], j_, j), dp[k][j])

    print('Case #{}: {}'.format(i+1, min(dp[n-1])))