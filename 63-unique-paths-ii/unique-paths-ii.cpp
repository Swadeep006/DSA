class Solution {
public:
    int uniquePathsWithObstaclesUtil(vector<vector<int>>& grid, int row, int col,vector<vector<int>>& dp) {
        if(grid[0][0]==1) return 0;
        dp[0][0]=1;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1) dp[i][j]=0;
                else{
                    if(i>0) dp[i][j]+=dp[i-1][j];
                    if(j>0) dp[i][j]+=dp[i][j-1];
                }
            }
        }
        return dp[row-1][col-1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>>dp(rows+1,vector<int>(cols+1));
        return uniquePathsWithObstaclesUtil(obstacleGrid, rows, cols, dp);
    }
};
