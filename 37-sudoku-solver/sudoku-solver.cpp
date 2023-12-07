#include <vector>

class Solution {
public:
    bool backtrack(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (checkValidGrid(board, num, i, j)) {
                            board[i][j] = num;
                            if (backtrack(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool checkValidGrid(const vector<vector<char>>& board, char num, int row, int col) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num)
                return false;

            if (board[i][col] == num)
                return false;

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
                return false;
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};
