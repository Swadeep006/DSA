vector<vector<int>>dp;
class Solution {
public:
    int helper(string &s1,string &s2, int n, int m){
        if(n==0 || m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s1[n-1]==s2[m-1]){
            return dp[n][m]=1+helper(s1,s2,n-1,m-1);
        }else{
            return dp[n][m]=max(helper(s1,s2,n-1,m),helper(s1,s2,n,m-1));
        }
        return dp[n][m];
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.assign(1001,vector<int>(1001,-1));
        return helper(text1,text2,text1.length(),text2.length());
    }
};