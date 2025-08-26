#include "header.h"

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int total = m * n;
        int count = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int i = 0, j = 0;
        int dir = 0;
        int iis[4] = {0, 1, 0, -1};
        int jjs[4] = {1, 0, -1, 0};
        vector<int> answer;
        while (count < total)
        {
            if (i >= m || i < 0 || j >= n || j < 0 || visited[i][j])
            {
                i -= iis[dir];
                j -= jjs[dir];
                dir++;
                dir %= 4;
                i += iis[dir];
                j += jjs[dir];
                continue;
            }

            answer.push_back(matrix[i][j]);
            count++;
            visited[i][j] = true;
            i += iis[dir];
            j += jjs[dir];
        }
        return answer;
    }
};