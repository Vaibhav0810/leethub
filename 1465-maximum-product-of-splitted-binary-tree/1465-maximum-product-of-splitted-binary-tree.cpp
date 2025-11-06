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
    long long findProduct(TreeNode* root, long long total, long long &ans) {
        if (!root) return 0;
        
        long long leftSum = findProduct(root->left, total, ans);
        long long rightSum = findProduct(root->right, total, ans);

        long long subTreeSum = root->val + leftSum + rightSum;

        long long rem = total - subTreeSum;
        ans = max(ans, subTreeSum * rem);

        return subTreeSum;
    }

    void sum(TreeNode* root, long long &s) {
        if (!root) return;
        sum(root->left, s);
        s += root->val;
        sum(root->right, s);
    }

    int maxProduct(TreeNode* root) {
        if (!root) return 0;
        long long total = 0;
        sum(root, total);

        long long ans = 0;
        findProduct(root, total, ans);

        const int MOD = 1e9 + 7;
        return ans % MOD;
    }
};
