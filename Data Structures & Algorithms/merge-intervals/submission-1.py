class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ans = []
        intervals.sort()

        for i in range(len(intervals)):
            if not ans:
                ans.append(intervals[i])
            else:
                prev_l = ans[-1][0]
                prev_r = ans[-1][1]
                l = intervals[i][0]
                r = intervals[i][1]

                if prev_l <= l <= prev_r:
                    if r > prev_r:
                        ans[-1][1] = r
                else:
                    ans.append(intervals[i])
        
        return ans