vector<vector<int>>dp;
class Solution {
public:
    int helper(string &s1, string &s2, int n, int m){
        if(n==0) return m;
        if(m==0) return n;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s1[n-1]==s2[m-1]){
            dp[n][m]=helper(s1,s2,n-1,m-1);
        }else{
            dp[n][m]=1+min(helper(s1,s2,n-1,m),min(helper(s1,s2,n,m-1),helper(s1,s2,n-1,m-1)));
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
       int n = word1.length();
       int m  = word2.length();
       dp.assign(n+1,vector<int>(m+1,-1));
        return helper(word1,word2,n,m);
    }
};