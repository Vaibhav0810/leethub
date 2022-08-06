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
    
            
//         // bst properties
//         Binary Search Tree is a node-based binary tree data structure which has the                  following properties:

//      The left subtree of a node contains only nodes with keys lesser than the node’s key.
//      The right subtree of a node contains only nodes with keys greater than the node’s key.
//       The left and right subtree each must also be a binary search tree.
        
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        
        if(root->val>p->val && root->val>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        if(root->val<p->val && root->val<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;
        
        
    }
};