class Solution:
    def minFlips(self, target: str) -> int:
        ret, state = 0, 0
        for c in target:
            if state != int(c):
                ret += 1
                state ^= 1
        return ret