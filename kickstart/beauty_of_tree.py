def dfs(start, depth):
    path[depth] = start
    if depth >= A:
        fa[start] = path[depth - A]
    if depth >= B:
        fb[start] = path[depth - B]
    if depth not in dnode:
        dnode[depth] = []
    dnode[depth].append(start)
    for c in ch[start]:
        dfs(c, depth+1)

T = int(input())
for t in range(T):
    N, A, B = list(map(int, input().split()))
    fa, fb, path, dnode = [-1] * N, [-1] * N, [-1] * N, {}
    ch = [[] for _ in range(N)]
    for c, p in enumerate(input().split()):
        ch[int(p)-1].append(c+1)
    dfs(0, 0)
    ans = 0
    pa, pb = [0] * N, [0] * N
    for d in sorted(dnode.keys(), reverse=True):
        for n in dnode[d]:
            pa[n] += 1 / N
            pb[n] += 1 / N
            ans += 1 - (1 - pa[n]) * (1 - pb[n])
            if fa[n] != -1:
                pa[fa[n]] += pa[n]
            if fb[n] != -1:
                pb[fb[n]] += pb[n]
    print('Case #{}: {}'.format(t+1, ans))