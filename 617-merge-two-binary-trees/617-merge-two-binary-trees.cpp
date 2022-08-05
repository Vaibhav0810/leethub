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
    
//     TreeNode* help(TreeNode* root1,TreeNode* root2){
//         TreeNode* merged=new TreeNode();
//         if(root1!=NULL && root2!=NULL){
//             merged->val=root1->val+root2->val;
          
//         }
        
//         else if(root1==NULL && root2!=NULL)
//             merged->val=root2->val;
//         else if(root2==NULL && root1!=NULL){
//             merged->val=root1->val;
//         }
        
//         help(root1->left,root2->left)&&help(root1->right,root2->right); 
    
        
//         return merged;
//     }
    
//     TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
//         if(root1==NULL && root2==NULL){
//             return 0;
//         }
        
//         return help(root1,root2);
        
//     }
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
};