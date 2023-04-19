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
       
    int pathLength=0;
    void dfs(TreeNode* root,int left,int right){
        if(root==NULL) return;
        pathLength=max(pathLength,max(left,right));
        
        if(root->left!=NULL) dfs(root->left,right+1,0);
        if(root->right) dfs(root->right,0,left+1);
        
    }
    
    int longestZigZag(TreeNode* root) {
        


        dfs(root,0,0);
        return pathLength;
    }
};