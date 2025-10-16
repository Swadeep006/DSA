/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode*root,bool flag){
        if(root==NULL) return 0;
        if(!root->left && !root->right){
            if(flag == true){
                return root->val;
            }else{
                return 0;
            }
        }
        return helper(root->left,true)+helper(root->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root,false);
    }
};