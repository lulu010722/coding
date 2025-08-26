#include "header.h"

class Solution
{
private:
    vector<string> board;
    bool column[10];
    bool cross1[20];
    bool cross2[20];
    int n;
    vector<vector<string>> solve(int m)
    {
        if (m == n)
            return {board};

        vector<vector<string>> answer;
        for (int i = 0; i < n; i++)
        {
            if (column[i] || cross1[i + m] || cross2[i - m + n - 1])
                continue;
            column[i] = cross1[i + m] = cross2[i - m + n - 1] = true;
            board[m][i] = 'Q';
            auto subAnswer = solve(m + 1);
            answer.insert(answer.end(), subAnswer.begin(), subAnswer.end());
            board[m][i] = '.';
            column[i] = cross1[i + m] = cross2[i - m + n - 1] = false;
        }
        return answer;
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        for (int i = 0; i < n; i++)
            board.push_back(string(n, '.'));
        memset(column, false, sizeof(column));
        memset(cross1, false, sizeof(cross1));
        memset(cross2, false, sizeof(cross2));
        this->n = n;
        return solve(0);
    }
};