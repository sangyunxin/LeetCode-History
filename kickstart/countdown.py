T = int(input())

for t in range(T):
    N, K = list(map(int, input().split()))
    A = list(map(int, input().split()))
    ret, i, l = 0, 0, 0
    while i < N:
        # print(A[i])
        if A[i] == K:
            flag = True
            for j in range(1, K):
                if i + j >= N or A[i+j] != A[i+j-1] - 1:
                    flag = False
                    break
            i += j - 1
            if flag: ret += 1
        i += 1
    print('Case #{}: {}'.format(t+1, ret))