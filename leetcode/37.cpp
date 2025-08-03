#include "header.h"

class Solution
{
private:
    bool line[9][9];
    bool column[9][9];
    bool block[3][3][9];
    vector<pair<int, int>> spaces;
    bool valid;

    void dfs(vector<vector<char>> &board, int index)
    {
        if (index == spaces.size())
        {
            valid = true;
            return;
        }

        auto [i, j] = spaces[index];
        for (int digit = 0; digit < 9 && !valid; digit++)
        {
            if (!line[i][digit] && !column[j][digit] && !block[i / 3][j / 3][digit])
            {
                line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
                board[i][j] = digit + 1 + '0';
                dfs(board, index + 1);
                line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = false;
            }
        }
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        memset(line, false, sizeof(line));
        memset(column, false, sizeof(column));
        memset(block, false, sizeof(block));
        valid = false;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    spaces.push_back({i, j});
                else
                {
                    int digit = board[i][j] - '0' - 1;
                    line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
                }
            }
        }
        dfs(board, 0);
    }
};