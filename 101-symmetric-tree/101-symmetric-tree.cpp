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
    
    bool help(TreeNode* left,TreeNode* right){
         if(left==NULL && right==NULL)   return true;
        if(left==NULL || right==NULL)   return false;
        if(left->val!=right->val){
            return false;
        }
        else{
            return help(left->left,right->right)&& help(left->right,right->left);
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL) return 0;
        return help(root->left,root->right);
        
    }
};

// isko chcek krna h iterative bhi solve krna h


// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//        bool check=false; 
//         if(root==NULL)
//             return 0;
//         TreeNode* lef=root;
//         TreeNode* righ=root;
        
//         while(lef!=NULL && righ!=NULL){
//             if(lef->val==righ->val){
//                 lef=lef->left;
//                 righ=righ->right;
//                 check=true;
//             }
//             else{
//                 check=false;
//                 return false;
//             }
//         }
//             lef=root;
//             righ=root;
            
//              while(lef!=NULL && righ!=NULL){
//             if(lef->val==righ->val){
//                 lef=lef->right;
//                 righ=righ->left;
//                 check=true;
//             }
//             else{
//                 check=false;
//                 return false;
//             }
//         }
//         if(check){
//             return true;
//         }
        
//         return false;
        
        
    
//     }
// };