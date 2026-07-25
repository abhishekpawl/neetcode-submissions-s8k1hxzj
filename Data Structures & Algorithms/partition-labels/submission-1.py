class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        last_pos = {}
        n = len(s)
        ans = []

        for idx, ch in enumerate(s):
            last_pos[ch] = idx
        
        start = 0
        end = 0
        i = 0

        for i in range(len(s)):
            end = max(end, last_pos[s[i]])

            if i == end:
                ans.append(end - start + 1)
                start = end + 1
        
        return ans