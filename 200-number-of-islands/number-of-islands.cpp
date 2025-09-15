class Solution {
public:
    vector<int>x4{-1,0,1,0};
    vector<int>y4{0,1,0,-1};
    void dfs(int i,int j, vector<vector<char>>&grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0'){
            return ;
        }
        grid[i][j]='0';
        for(int d=0;d<4;d++){
            dfs(i+x4[d],j+y4[d],grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int k =0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    k++;
                }
            }
        }
        return k;
    }
};