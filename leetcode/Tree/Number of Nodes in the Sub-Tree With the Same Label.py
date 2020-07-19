class Solution:
    ret = None
    cur_ret = {}

    def dfs(self, start, g, visit, labels):
        if labels[start] not in self.cur_ret:
            self.cur_ret[labels[start]] = 1
        else:
            self.cur_ret[labels[start]] += 1
        tmp = self.cur_ret[labels[start]]
        visit.add(start)
        for n in g[start]:
            if n not in visit:
                self.dfs(n, g, visit, labels)
        # print(start, self.cur_ret)
        self.ret[start] = self.cur_ret[labels[start]] - tmp + 1


    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        self.ret = [0] * n
        g = [[] for _ in range(n)]
        for e in edges:
            g[e[0]].append(e[1])
            g[e[1]].append(e[0])
        self.dfs(0, g, set(), labels)
        return self.ret