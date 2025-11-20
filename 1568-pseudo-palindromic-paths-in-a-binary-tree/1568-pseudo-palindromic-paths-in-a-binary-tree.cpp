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
    int ans = 0;
    void checkPalindrome(vector<int> v) {
        unordered_map<int, int> mp;
        int count = 0;
        for (int i = 0; i < 10; i++) {
            if (v[i] > 0) {
                count+=v[i];
                mp[i] = v[i];
            }
        }

        if (count % 2 == 0) {
            for (auto it : mp) {
                if (it.second % 2 != 0) {
                    return;
                }
            }
            ans++;
        } else {
            bool odd = false;
            for (auto it : mp) {
                if (it.second % 2 != 0 && !odd) {
                    odd = true;
                } else if (it.second % 2 != 0)
                    return;
            }
            ans++;
        }
    }

    void dfs(TreeNode* root, vector<int> store) {
        if (root == NULL)
            return;
        store[root->val]++;
        if (!root->left && !root->right) {
            checkPalindrome(store);
            return;
        }
        dfs(root->left, store);
        dfs(root->right, store);
    }

    int pseudoPalindromicPaths(TreeNode* root) {
        if (root == NULL)
            return 0;
        // int ans= 0;
        vector<int> store(10, 0);
        dfs(root, store);

        return ans;
    }
};