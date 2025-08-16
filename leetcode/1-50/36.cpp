#include "header.h"

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            set<int> row;
            set<int> column;
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.' && !row.insert(board[i][j]).second)
                    return false;
                if (board[j][i] != '.' && !column.insert(board[j][i]).second)
                    return false;
            }
        }

        for (int ii = 0; ii < 3; ii++)
        {
            for (int jj = 0; jj < 3; jj++)
            {
                set<int> grid;
                for (int i = 3 * ii; i < 3 * ii + 3; i++)
                {
                    for (int j = 3 * jj; j < 3 * jj + 3; j++)
                    {
                        if (board[i][j] != '.' && !grid.insert(board[i][j]).second)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};