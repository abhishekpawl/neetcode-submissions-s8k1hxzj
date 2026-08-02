class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        ans = [0] * len(temperatures)

        for idx, temp in enumerate(temperatures):
            if not stack:
                stack.append((temp, idx))
            else:
                while stack and stack[-1][0] < temp:
                    x = stack.pop()
                    ans[x[1]] = idx - x[1]
                stack.append((temp, idx))
        
        return ans