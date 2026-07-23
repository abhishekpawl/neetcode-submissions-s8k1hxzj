class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        diff = [0] * n

        for i in range(n):
            diff[i] = gas[i] - cost[i]
        
        if sum(diff) < 0:
            return -1
        
        curr = 0
        maxCurr = 0
        ans = -1

        for i in range(n-1, -1, -1):
            curr += diff[i]
            if curr >= maxCurr:
                maxCurr = curr
                ans = i
        
        return ans