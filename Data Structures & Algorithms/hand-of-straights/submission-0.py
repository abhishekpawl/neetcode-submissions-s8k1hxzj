from collections import Counter

class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        hand.sort()
        freq = Counter(hand)

        flag = 1

        for val in hand:
            if freq.get(val) > 0:
                for i in range(val, val + groupSize):
                    if freq.get(i, 0) == 0:
                        flag = 0
                        break
                    else:
                        freq[i] -= 1
                if flag == 0:
                    break
        
        return True if flag else False