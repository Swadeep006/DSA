vector<int>dp;
class Solution {
public:
    int helper(vector<int>& nums, int index){
        if(index<0) return 0;
        if(dp[index]!=-1) return dp[index];
        int notTake = helper(nums,index-1);
        int take = nums[index]+helper(nums,index-2);
        return dp[index]= max(take,notTake);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        dp.assign(101,-1);
        return helper(nums,nums.size()-1);
    }
};