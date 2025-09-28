vector<int> dp;
class Solution {
public:
    int minCut(string s) {
        dp.assign(2001, -1);
        int n = s.size();
        return helper(s, n, 0) - 1;
    }

    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    int helper(string& s, int n, int i) {
        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = INT_MAX;
        for (int k = i; k < n; k++) {
            if (isPalindrome(s, i, k)) {
                dp[i] = helper(s, n, k + 1) + 1;
                ans = min(ans, dp[i]);
            }
        }
        return dp[i] = ans;
    }
};