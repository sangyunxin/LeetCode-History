class Solution:
    def closestToTarget(self, arr: List[int], target: int) -> int:
        ans = abs(arr[0] - target)
        valid = {arr[0]}
        for num in arr:
            valid = {v & num for v in valid} | {num}
            ans = min(ans, min(abs(v - target) for v in valid))
        return ans