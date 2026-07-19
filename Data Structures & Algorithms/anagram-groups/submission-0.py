from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = defaultdict(list)
        for x in strs:
            li = [0] * 26
            for ch in x:
                li[ord(ch) - ord('a')] += 1
            mp[tuple(li)].append(x)
        return list(mp.values())