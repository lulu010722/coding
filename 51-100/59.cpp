#include "header.h"

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> answer(n, vector<int>(n, 0));
        int i = 0, j = 0;
        int dir = 0;
        int iis[4] = {0, 1, 0, -1};
        int jjs[4] = {1, 0, -1, 0};
        int total = n * n;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for (int k = 0; k < total; k++)
        {
            if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j])
            {
                i -= iis[dir];
                j -= jjs[dir];
                dir++;
                dir %= 4;
                i += iis[dir];
                j += jjs[dir];
                k--;
                continue;
            }
            answer[i][j] = k + 1;
            visited[i][j] = true;
            i += iis[dir];
            j += jjs[dir];
        }
        return answer;
    }
};