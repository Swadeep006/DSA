class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 2;
        int count = 2;
        for (int i = 2; i < n; i++) {
            if (nums[i] == nums[i - 1] + nums[i - 2]) {
                count = count + 1;
            } else {
                count = 2;
            }
            res = max(res,count);
        }
        return res;
        
    }
};