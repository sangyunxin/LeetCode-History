class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        T, D = set(), [0] * n
        g = [[] for _ in range(n)]
        for i, e in enumerate(edges):
            g[e[0]].append((e[1], succProb[i]))
            g[e[1]].append((e[0], succProb[i]))
        q = [(-1, start)]
        while q:
            cd, cp = heapq.heappop(q) 
            if cp == end:
                return -cd
            for np, nd in g[cp]:
                if cd * nd < D[np]:
                    D[np] = cd * nd
                    heapq.heappush(q, (D[np], np))
        return 0