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

class Solution 
{
public:
    vector<string>path;
    void helper(TreeNode* root,string a)
    {
        if(root==NULL)return ;
        a=a+to_string(root->val);
        if(root->left==NULL && root->right == NULL){
            cout<<a<<endl;
            path.push_back(a);
            return ;
        }
        helper(root->left,a+"->");
        helper(root->right,a+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        path.clear();
        helper(root,"");
        return path;
    }
};