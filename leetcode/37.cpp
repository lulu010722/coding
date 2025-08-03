#include "header.h"

class Solution
{
private:
    struct Point
    {
        int x, y;
        int rowRemain, columnRemain, gridRemain;
        Point(int x, int y) : x(x), y(y), rowRemain(0), columnRemain(0), gridRemain(0) {}
        Point(int x, int y, int row, int column, int grid) : x(x), y(y), rowRemain(row), columnRemain(column), gridRemain(grid) {}
        bool operator<(const Point &other) const
        {
            return rowRemain + columnRemain + gridRemain < other.rowRemain + other.columnRemain + other.gridRemain;
        }
    };

    bool solve(vector<vector<char>> &board, deque<pair<int, int>> &remain)
    {
        if (remain.size() == 0)
            return true;
        set<char> row, column, grid;
        int first = remain[0].first;
        int second = remain[0].second;
        int ii = first / 3;
        int jj = second / 3;

        for (int i = 0; i < 9; i++)
        {
            if (i != second)
                column.insert(board[first][i]);
            if (i != first)
                row.insert(board[i][second]);
        }
        for (int i = 3 * ii; i < 3 * ii + 3; i++)
            for (int j = 3 * jj; j < 3 * jj + 3; j++)
                if (i != first || j != second)
                    grid.insert(board[i][j]);

        for (char c = '1'; c <= '9'; c++)
        {
            if (!row.insert(c).second || !column.insert(c).second || !grid.insert(c).second)
                continue;
            board[first][second] = c;
            remain.pop_front();
            if (solve(board, remain))
                return true;
            remain.push_front({first, second});
            board[first][second] = '.';
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        deque<pair<int, int>> remain;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.')
                    remain.push_back({i, j});
        solve(board, remain);
    }
};