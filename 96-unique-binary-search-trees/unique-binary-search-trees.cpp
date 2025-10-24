int dp[20] = {0};
class Solution {
public:

    int numTrees(int n) {
        dp[0] = 1; 
        dp[1] = 1; 
        for(int i = 2;i <= n; i++){
            int val = 0;
           for(int j = 1; j <= i; j++){
            val += dp[j - 1] * dp[i - j];
           }
           dp[i] = val;
        }
        return dp[n];
     }
};