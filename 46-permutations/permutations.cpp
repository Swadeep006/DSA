class Solution {
public:
    void helper(vector<int>&nums,vector<int>&visitedArr,vector<int>&path,vector<vector<int>>&paths){
        if(path.size()==nums.size()){
            paths.push_back(path);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(!visitedArr[i]){
                path.push_back(nums[i]);
                visitedArr[i]=1;
                helper(nums,visitedArr,path,paths);
                path.pop_back();
                visitedArr[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        //creation of solution vectors
        vector<int>path;
        vector<vector<int>>paths;

        //creation of visited Array prefilled with false i.e 0's
        vector<int>visitedArr(nums.size(),0);

        //calling helper function
        helper(nums,visitedArr,path,paths);

        return paths;        
    }
};