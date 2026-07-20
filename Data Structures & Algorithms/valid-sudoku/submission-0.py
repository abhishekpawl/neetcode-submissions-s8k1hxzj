class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        maskx = [0] * 9
        masky = [0] * 9
        maskbox = [[0] * 3 for _ in range(3)]
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    continue
                digit = ord(board[i][j]) - ord('0')
                x = int(i / 3)
                y = int(j / 3)
                if maskx[i] & (1 << digit):
                    return False
                if masky[j] & (1 << digit):
                    return False
                if maskbox[x][y] & (1 << digit):
                    return False
                maskx[i] |= (1 << digit)
                masky[j] |= (1 << digit)
                maskbox[x][y] |= (1 << digit)
        return True