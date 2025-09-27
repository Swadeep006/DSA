vector<vector<int>>dp;
class Solution {
public:
    int helper(vector<int>& arr, int i, int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MIN;
        for(int k=i;k<=j;k++){
            dp[i][j]=helper(arr,i,k-1)+helper(arr,k+1,j)+arr[i-1]*arr[k]*arr[j+1];
            ans = max(ans,dp[i][j]);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        dp.assign(301,vector<int>(301,-1));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return helper(nums,1,nums.size()-2);
    }
};