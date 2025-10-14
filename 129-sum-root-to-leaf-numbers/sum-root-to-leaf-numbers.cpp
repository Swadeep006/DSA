/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long ans = 0;
    void helper(TreeNode* root, int total){
        if(root==NULL) return ;
        long sum = stol(to_string(total)+to_string(root->val));
        cout<<sum<<endl;
        if(root->left==NULL && root->right==NULL){
            ans+=sum;
            return ;
        }
        helper(root->left,sum);
        helper(root->right,sum);
    }
    int sumNumbers(TreeNode* root) {
        ans=0;
        if(root==NULL) return 0;
        helper(root,0);
        return ans;
    } 
};