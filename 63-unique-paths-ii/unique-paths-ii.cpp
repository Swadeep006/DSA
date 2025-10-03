class Solution {
public:
    int uniquePathsWithObstaclesUtil(vector<vector<int>>& grid, int row, int col,vector<vector<int>>& dp) {
        // Safe order of base checks
        if (row < 0 || col < 0 || grid[row][col] == 1) {
            return 0;
        }
        if (row == 0 && col == 0) {
            return 1;
        }
        if (dp[row][col] != 0) {
            return dp[row][col] ;
        }

        int up = uniquePathsWithObstaclesUtil(grid, row - 1, col, dp);
        int left = uniquePathsWithObstaclesUtil(grid, row, col - 1, dp);

        return dp[row][col] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>>dp(rows+1,vector<int>(cols+1));
        return uniquePathsWithObstaclesUtil(obstacleGrid, rows - 1, cols - 1, dp);
    }
};
