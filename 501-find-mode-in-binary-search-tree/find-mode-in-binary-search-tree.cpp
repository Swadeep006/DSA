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
    void helper(TreeNode* root, map<int, int>& mp) {
        if (!root) return;
        mp[root->val]++;
        helper(root->left, mp);
        helper(root->right, mp);
    }

    vector<int> findMode(TreeNode* root) {
        map<int, int> mp;
        helper(root, mp);

        int maxFreq = 0;
        for (auto& it : mp)
            maxFreq = max(maxFreq, it.second);  

        vector<int> ans;
        for (auto& it : mp) {
            if (it.second == maxFreq)
                ans.push_back(it.first);
        }

        return ans;
    }
};
