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
   
    bool ans;
    
    int help(TreeNode* root){
         if(!root) return 0;
        if(!ans) return 0;
       
        int heightL=help(root->left);
        int heightR=help(root->right);
        
      
        if(abs(heightL-heightR)>1) ans=false;
         
        return 1+max(heightL,heightR);
    }
    
    bool isBalanced(TreeNode* root) {
        ans=true;
        
       int temp=help(root);
        return ans;
        
    }
};