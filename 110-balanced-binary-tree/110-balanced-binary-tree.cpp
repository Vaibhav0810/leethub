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
        
        if(!root) return 0; //iska mtlb h if root==NULL 
        
        if(ans==false) return 0; 
        
        int lH=help(root->left);
        int rh=help(root->right);
        
        if(abs(lH-rh)>1){
            ans=false;
        }
        
        return 1+max(lH,rh);
        
    }
    
    bool isBalanced(TreeNode* root) {
        ans=true;
        help(root);
        return ans;
        
        
    }
};