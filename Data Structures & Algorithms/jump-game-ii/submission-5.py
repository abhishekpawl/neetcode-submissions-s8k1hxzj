class Solution:
    def jump(self, nums: List[int]) -> int:
        l = 0
        r = 0
        maxReach = 0
        n = len(nums)
        bfs_level = 0 # jumps

        while r < n-1:
            bfs_level += 1
            for i in range(l, r+1):
                maxReach = max(maxReach, min(n-1, i + nums[i]))
            l = r + 1
            r = maxReach
        
        return bfs_level