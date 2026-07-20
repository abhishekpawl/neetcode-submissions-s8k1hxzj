class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        left = [0] * n

        for i in range(n):
            if i == 0:
                left[i] = height[i]
            else:
                left[i] = max(left[i-1], height[i])
        
        right = 0
        ans = 0

        for i in range(n-1, -1, -1):
            if i == n-1:
                right = height[i]
            else:
                right = max(right, height[i])
            
            ans += min(left[i], right) - height[i]

        return ans