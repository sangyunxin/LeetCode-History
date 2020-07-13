T = int(input())
for i in range(T):
    N = int(input())
    V = list(map(int, input().split(' ')))
    ret, local_max = 0, 0
    for j in range(N):
        gp = (j == 0 or V[j] > local_max)
        gf = (j == N - 1 or V[j] > V[j+1])
        if gp and gf:
            ret += 1
        local_max = max(V[j], local_max)
    print('Case #{0}: {1}'.format(i+1, ret))