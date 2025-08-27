#include "header.h"

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> ways(m, vector<int>(n, 1));
        if (obstacleGrid[0][0] == 1)
            return 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    ways[i][j] = 0;
                else
                    ways[i][j] = (i - 1 >= 0 ? ways[i - 1][j] : 0) + (j - 1 >= 0 ? ways[i][j - 1] : 0), ways[0][0] = 1;
            }
        }
        return ways[m - 1][n - 1];
    }
};