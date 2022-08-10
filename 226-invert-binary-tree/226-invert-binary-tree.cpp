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
    TreeNode* invertTree(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        
        // kuch dimag ni lgana bs aise soch mai phla kr rha hu invert tum mujhe baaki krke dedo simple
        
        invertTree(root->left);
        invertTree(root->right);
        
        // sirf invert se km ch jaayega dont waste memory
        TreeNode* invert;
        invert=root->left;
        root->left=root->right;
        root->right=invert;
        
        return root;
        
    }
    
};