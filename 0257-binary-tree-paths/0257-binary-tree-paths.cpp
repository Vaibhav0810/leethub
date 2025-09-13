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

    void dfs(TreeNode* root, string s, vector<string>&ans){
        if(root==NULL) return;
        if(!root->left && !root->right){
            s=s+to_string(root->val);
            ans.push_back(s);
            return;
        }

        dfs(root->left,s+to_string(root->val)+"->",ans);
        dfs(root->right,s+to_string(root->val)+"->",ans);

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL) return {};
        string s="";
        vector<string>ans;
        dfs(root,s,ans);
        return ans;
    }
};