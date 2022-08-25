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
    
    // making a new tree
    
    TreeNode* help(TreeNode* root1,TreeNode* root2){
        
        if(root1 && root2){
        
        TreeNode* merged=new TreeNode(root1->val+root2->val);
        
        
        merged->left=help(root1->left,root2->left) ;
        merged->right=help(root1->right,root2->right);  
            return merged;
        }
        else{
            if(root1==NULL && root2!=NULL){
                return root2;
            }
            else return root1;
        }
        
        
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        
        
         return help(root1,root2);
        
     }
    
    // merging in the same tree
    
    // https://leetcode.com/problems/merge-two-binary-trees/discuss/588123/~100.00-fast-in-run-time-and-memory-RecursiveIterativeBFSDFS
  /*  
    TreeNode* mergeTrees(TreeNode* t1,TreeNode *t2){
        if(t1 && t2){
            TreeNode* root=new TreeNode(t1->val+t2->val);
            root->left=mergeTrees(t1->left,t2->left);
            root->right=mergeTrees(t1->right,t2->right);
            return root;
        }
        else{
            return t1?t1:t2;
        }
    }
    */
};