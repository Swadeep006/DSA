vector<vector<long>> dp(31, vector<long>(31, 1));
class Solution {
public:
    void pascals() {
        for (long i = 2; i < 31; i++) {
            for (long j = 1; j < i; j++) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }
    vector<vector<int>> generate(int numRows) {
        pascals();
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            ans.push_back(vector<int>(dp[i].begin(), dp[i].begin() + i + 1));
        }
        return ans;
    }
};