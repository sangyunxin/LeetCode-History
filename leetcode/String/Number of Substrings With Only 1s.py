class Solution:
    def numSub(self, s: str) -> int:
        ret, count = 0, 0
        for c in s:
            if c == '1':
                count += 1
            elif count > 0:
                # print(count)
                ret += (count * (1 + count) / 2) % (1e9 + 7)
                count = 0
        ret += (count * (1 + count) / 2) % (1e9 + 7)
        return int(ret % (1e9 + 7))