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
    int helper(TreeNode* root, long long currSum, int target,unordered_map<long long, int>& mp) {
        if (!root) return 0;
        currSum += root->val;
        int count = 0;
        if (mp.count(currSum - target)) {
            count += mp[currSum - target];
        }
        mp[currSum]++;
        count += helper(root->left, currSum, target, mp);
        count += helper(root->right, currSum, target, mp);
        mp[currSum]--;
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> mp;
        mp[0] = 1; 
        return helper(root, 0, targetSum, mp);
    }
};