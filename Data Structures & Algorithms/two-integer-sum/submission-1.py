class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}
        for idx, num in enumerate(nums):
            if num not in mp:
                mp[num] = idx
        for idx, num in enumerate(nums):
            x = target - num
            if x not in mp:
                continue
            if mp[x] == idx:
                continue
            return sorted([idx, mp[x]])
        return [-1, -1]