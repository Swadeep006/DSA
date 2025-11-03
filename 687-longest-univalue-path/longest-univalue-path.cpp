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
    int maxi = INT_MIN;

public:
    int helper(TreeNode* root) {
        if (!root)
            return 0;
        int lst = helper(root->left);
        int rst = helper(root->right);
        int ra = 0, la = 0;
        if (root->left && root->val == root->left->val) {
            la = lst;
        }
        if (root->right && root->val == root->right->val) {
            ra = rst;
        }
        maxi = max(maxi, la + ra + 1);
        return max(la, ra) + 1;
    }
    int longestUnivaluePath(TreeNode* root) {
        helper(root);
        return maxi > 0 ? maxi - 1 : 0;
    }
};