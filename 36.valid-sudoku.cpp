class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int state = 0;
        for (int i = 0; i < 9; i++) {
            state = 0;
            for (int j = 0; j < 9; j++) if (board[i][j] != '.') {
                if (state & (1 << (board[i][j]-'0'))) return false;
                state |= 1 << (board[i][j]-'0');
            }
        }
        for (int j = 0; j < 9; j++) {
            state = 0;
            for (int i = 0; i < 9; i++) if (board[i][j] != '.') {
                if (state & (1 << (board[i][j]-'0'))) return false;
                state |= 1 << (board[i][j]-'0');
            }
        }
        for (int di = 0; di < 9; di += 3)
            for (int dj = 0; dj < 9; dj += 3) {
                state = 0;
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 3;j ++)
                        if (board[i+di][j+dj] != '.') {
                            if (state & (1 << (board[i+di][j+dj]-'0'))) return false;
                            state |= 1 << (board[i+di][j+dj]-'0');
                        }
            }
        return true;                
    }
};