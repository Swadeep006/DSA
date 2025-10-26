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
 vector<vector<int>>paths;
 vector<int>path;
class Solution {
public:
    void helper(TreeNode*root,int target,vector<int>&path,vector<vector<int>>&paths){
        if(!root) return ;
        path.push_back(root->val);
        target = target-root->val;
        if(!root->left && !root->right){
            if(target==0){
                paths.push_back(path);
            }
            path.pop_back();
            return;
        }
        helper(root->left,target,path,paths);
        helper(root->right,target,path,paths);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        paths.clear();
        path.clear();
        helper(root,targetSum,path,paths);
        return paths;
    }
};