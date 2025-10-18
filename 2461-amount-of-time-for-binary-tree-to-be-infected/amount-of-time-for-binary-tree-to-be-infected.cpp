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
    bool flag = false;
    void findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (!root || flag) {
            return;
        }
        if (root == target) {
            path.push_back(root);
            flag = true;
            return;
        }
        path.push_back(root);
        findPath(root->left, target, path);
        findPath(root->right, target, path);
        if (!flag) {
            path.pop_back();
        }
    }
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    TreeNode* req;
    void search(TreeNode* root, int target) {
        if (!root)
            return;
        if (root->val == target) {
            req = root;
            return;
        }
        search(root->left, target);
        search(root->right, target);
    }
    int amountOfTime(TreeNode* root, int start) {
        flag = false;
        req = nullptr;
        if (!root)
            return 0;
        vector<TreeNode*> path;
        search(root, start);
        if (!req)
            return 0;
        findPath(root, req, path);
        reverse(path.begin(), path.end());

        int time = -1;
        time = maxDepth(path[0]) - 1;
        for (int i = 1; i < path.size(); i++) {
            if (path[i]->left == path[i - 1]) {
                if (path[i]->right)
                    time = max(time, i + maxDepth(path[i]->right));
                else
                    time = max(time, i); 
            } else if (path[i]->right == path[i - 1]) {
                if (path[i]->left)
                    time = max(time, i + maxDepth(path[i]->left));
                else
                    time = max(time, i); 
            }
        }
        return time;
    }
};