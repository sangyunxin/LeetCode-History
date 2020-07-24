class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        num_count = {}
        ret = 0
        for num in nums:
            if num not in num_count:
                num_count[num] = 0
            ret += num_count[num]
            num_count[num] += 1
        return ret