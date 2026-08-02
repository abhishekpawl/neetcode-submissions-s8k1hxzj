class Solution:
    def isValid(self, s: str) -> bool:
        balance = []

        for ch in s:
            if ch == ')' and len(balance) and balance[-1] == '(':
                balance.pop()
            elif ch == '}' and len(balance) and balance[-1] == '{':
                balance.pop()
            elif ch == ']' and len(balance) and balance[-1] == '[':
                balance.pop()
            else:
                balance.append(ch)
        
        return not len(balance)