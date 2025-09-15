class Solution {
public:
    vector<int>x4{-1,0,1,0};
    vector<int>y4{0,1,0,-1};
    int dfs(int i,int j, vector<vector<int>>&grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0){
            return 0 ;
        }
        grid[i][j]=0;
        int count =1;
        for(int d=0;d<4;d++){
            count += dfs(i+x4[d],j+y4[d],grid);
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int k =0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int area = dfs(i,j,grid);
                    k = max(area,k);
                }
            }
        }
        return k;
    }
};