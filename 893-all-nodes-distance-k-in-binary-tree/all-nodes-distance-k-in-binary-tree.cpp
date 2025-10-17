/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (!root)
            return false;
        path.push_back(root);
        if (root == target) {
            return true;
        }
        if (findPath(root->left, target, path) ||
            findPath(root->right, target, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }
    void nodesAtKlevel(TreeNode* root, int target, int count,
                       vector<int>& ans) {
        if (!root)
            return;
        if (target == count) {
            ans.push_back(root->val);
            return;
        }
        nodesAtKlevel(root->left, target, count + 1, ans);
        nodesAtKlevel(root->right, target, count + 1, ans);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> path;
        vector<int> ans;
        if (!findPath(root, target, path))
            return ans;
        reverse(path.begin(), path.end());
        nodesAtKlevel(path[0], k, 0, ans);
        for (int i = 1; i < path.size(); i++) {
            if (i == k) {
                ans.push_back(path[i]->val);
                break;
            }
            TreeNode* sibling =
                (path[i]->left == path[i - 1]) ? path[i]->right : path[i]->left;
            int need = k - i - 1;
            if (sibling && need >= 0)
                nodesAtKlevel(sibling, need, 0, ans);
        }
        return ans;
    }
};