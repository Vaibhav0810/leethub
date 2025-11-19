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
    unordered_map<int, vector<int>> adj;
    void makeGraph(TreeNode* root, int parent) {
        if (root == NULL)
            return;
        if (parent != -1) {
            adj[root->val].push_back(parent);
        }
        if (root->left) {
            adj[root->val].push_back(root->left->val);
        }
        if (root->right) {
            adj[root->val].push_back(root->right->val);
        }
        makeGraph(root->left, root->val);
        makeGraph(root->right, root->val);
    }

    vector<int> ans;

    void dfs(int root, int parent, int k) {
        if (k == 0) {
            ans.push_back(root);
            return;
        }
        for (auto it : adj[root]) {
            if (it != parent) {
                dfs(it, root, k - 1);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (root == NULL)
            return {};
        // convert tree to graph
        makeGraph(root, -1);

        // dfs on graph
        vector<int>visi(501,0);
        dfs(target->val, target->val, k);

        return ans;
    }
};