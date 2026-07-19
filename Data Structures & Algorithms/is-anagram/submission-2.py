class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        mp_s = {}
        for x in s:
            if x not in mp_s:
                mp_s[x] = 1
            else:
                mp_s[x] += 1
        mp_t = {}
        for x in t:
            if x not in mp_t:
                mp_t[x] = 1
            else:
                mp_t[x] += 1
        for key, val in mp_s.items():
            if key not in mp_t:
                return False
            if mp_t[key] != val:
                return False
        return True