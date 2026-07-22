class Solution:
    def canJump(self, nums: List[int]) -> bool:
        carry = nums[0]

        for i in range(1, len(nums)-1):
            carry = max(carry-1, nums[i])
            if carry <= 0:
                return False
        
        if len(nums) > 1 and nums[0] <= 0:
            return False

        return True