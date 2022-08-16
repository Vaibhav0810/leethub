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
    // brute time-O(N^2)
  /* int height(TreeNode* root){
        if(root==NULL) return 0;
        
        return max(height(root->left),height(root->right))+1;
    }
    
    bool isBalanced(TreeNode* root) {
        
        if(root==NULL) return 1;
        //isBalanced(root->left);
        int lh=height(root->left);
        int rh=height(root->right);
        
        
        if(abs(lh-rh)>1) return false;
        else return isBalanced(root->left) && isBalanced(root->right);
    }
};
*/  
// optimal O(N) bottom up approach
    bool ans;
    int help(TreeNode* root){
        if(root==NULL) return 0;
        if(ans==false) return 0;
        
        int lh=help(root->left);
        int rh=help(root->right);
        
        if(abs(lh-rh)>1) ans=false;
        return 1+max(lh,rh);
    }
    
    bool isBalanced(TreeNode* root){
    
        
        ans=true;
        help(root);
        return ans;
    
        
    }
};
