class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        ranges = {}

        for idx, ch in enumerate(s):
            if ch not in ranges:
                ranges[ch] = [idx, idx]
            else:
                ranges[ch][1] = idx
        
        intervals = list(ranges.values())
        intervals.sort()

        final_intervals = []

        for interval in intervals:
            if not final_intervals:
                final_intervals.append(interval[:])
            else:
                l = interval[0]
                r = interval[1]
                curr = final_intervals[-1]
                if curr[0] <= l <= curr[1]:
                    if r > curr[1]:
                        curr[1] = r
                else:
                    final_intervals.append(interval[:])
        
        ans = [0] * len(final_intervals)

        for i in range(len(final_intervals)):
            ans[i] = final_intervals[i][1] - final_intervals[i][0] + 1
        
        return ans