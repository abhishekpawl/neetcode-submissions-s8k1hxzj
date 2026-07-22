class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        s = 0
        max_sum = -1000

        for i in range(len(nums)):
            if s < 0:
                s = 0
            s += nums[i]
            if s > max_sum:
                max_sum = s
        
        return max_sum