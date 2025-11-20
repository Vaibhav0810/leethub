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
    int findBottomLeftValue(TreeNode* root) {
        // do bfs n on last level call the first value
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            int n = q.size();
            bool first = true;
            while (n--) {
                auto top = q.front();
                q.pop();
                if (first) {
                    ans = top->val;
                    first = false;
                }
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
        }
        return ans;
    }
};