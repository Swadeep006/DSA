vector<vector<long>> dp(31, vector<long>(31, 1));
class Solution {
public:
    // vector<vector<int>> dp(31,vector<int>(31,1));
    void pascals() {
        for (long i = 0; i < 31; i++) {
            dp[i][0] = 1; // first element of each row
            dp[i][i] = 1; // last element of each row
        }
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
            // Insert first i+1 elements from dp[i] directly
            ans.push_back(vector<int>(dp[i].begin(), dp[i].begin() + i + 1));
        }
        return ans;
    }
};