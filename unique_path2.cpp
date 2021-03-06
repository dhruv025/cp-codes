class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int rows = obstacleGrid.size();
        if(rows == 0)
            return 0;
        int cols = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1)
            return 0;
        if(obstacleGrid[0][0] == 0)
                obstacleGrid[0][0] = 1;
        for(int i = 1; i < cols; ++i)
        {
            if(obstacleGrid[0][i] == 1)
                obstacleGrid[0][i] = 0;
            else
                obstacleGrid[0][i] = obstacleGrid[0][i-1];
        }
        for(int i = 1; i < rows; ++i)
        {
            if(obstacleGrid[i][0] == 1)
                obstacleGrid[i][0] = 0;
            else
                obstacleGrid[i][0] = obstacleGrid[i-1][0];   
        }
        for(int i = 1; i < rows; ++i)
        {
            for(int j = 1; j < cols; ++j)
            {
                if(obstacleGrid[i][j] == 0)
                    obstacleGrid[i][j] = obstacleGrid[i][j-1] + obstacleGrid[i-1][j];
                else
                    obstacleGrid[i][j] = 0;
            }
        }
        return obstacleGrid[rows-1][cols-1];
    }
};
