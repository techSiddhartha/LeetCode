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
    int maxSum = INT_MIN;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        // Compute max gain from left and right subtrees
        int left = max(0, dfs(root->left));   // take 0 if negative
        int right = max(0, dfs(root->right)); // take 0 if negative

        // Current max path at this node
        int currentPath = root->val + left + right;

        // Update global max path sum
        maxSum = max(maxSum, currentPath);

        // Return max gain if continuing the same path upwards
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
