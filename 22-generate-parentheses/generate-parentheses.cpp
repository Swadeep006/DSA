vector<string>ans;
class Solution {
public:
    void helper(int left, int right, int n, string res){
        if(left==n && right == n){
            ans.push_back(res);
            return ;
        }
        if(left<n){
            helper(left+1,right,n,res+"(");
        }
        if(left>right){
            helper(left,right+1,n,res+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        helper(0,0,n,"");
        return ans;
    }
};