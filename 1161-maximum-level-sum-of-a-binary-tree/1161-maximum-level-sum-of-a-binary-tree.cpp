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
    int maxLevelSum(TreeNode* root) {
        int level = 1;
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        int maxi = INT_MIN;
        
        while (!q.empty()) {
            int n = q.size();
            int sum = 0;
            while (n--) {
                auto x = q.front();
                sum+=x->val;
                q.pop();
                if (x->left) {
                    q.push(x->left);
                }
                if (x->right)
                    q.push(x->right);
            }
            if(sum>maxi){
                maxi = sum;
                ans=level;
            }
            level++;
        }

        return ans;
    }
};