class Solution:
    def isPalindrome(self, s: str) -> bool:
        trunc = ""
        s = s.lower()
        for ch in s:
            if ord('a') <= ord(ch) <= ord('z') or ord('0') <= ord(ch) <= ord('9'):
                trunc += ch
        l = 0
        r = len(trunc) - 1
        while l < r:
            if trunc[l] != trunc[r]:
                return False
            l += 1
            r -= 1
        return True