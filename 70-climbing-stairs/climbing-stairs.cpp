class Solution {
public:
    int climbStairsUtil(vector<int>& memo, int n){
        if(n<=1) return 1;
        if(memo[n]!=0) return memo[n];
        memo[n] = climbStairsUtil(memo,n-1)+climbStairsUtil(memo,n-2);
        return memo[n];
    }
    int climbStairs(int n) {
        vector<int>memo(n+1);
        return climbStairsUtil(memo,n);
    }
};