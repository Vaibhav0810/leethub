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
    //              WATCH NOTES FOR ONE MORE AND BETTER APPROACH    
    // iss vale solution mei [2147483647] ye test case pass ni hoga bcoz INT_MAX ki value itni ni hoti
    // same for minimum
    // long pass krenege to chl jayega
     bool help(TreeNode* root,long max,long min){
         if(root==NULL) return 1;
             
             if(root->val>min && root->val<max){
                 return help(root->right,max,root->val) && help(root->left,root->val,min);
             }
         else return false;
             
     }
    
    bool isValidBST(TreeNode* root) {
        
        // ye aaproach bhi ni chlegi bcoz ye sirf right left se check kr rha h ki bda chota h ya ni 
        // bt major node se ni
        
//         if(root==NULL) return 1;
//         if(root->left==NULL && root->right==NULL) return 1;
      
        
//         if(root->left==NULL&& root->right!=NULL){
//             if(root->right->val>!root->val){
//                 return false;
//             }
//         }
//         else if(root->right==NULL&& root->left!=NULL){
//             if(root->left->val<!root->val) return 0;
//         }
//         else if(root->right!=NULL && root->left!=NULL){
//         if(root->left->val<!root->val && root->right->val>!root->val){
//             return 0;
//         }
//         }
//         //else{return false;}
        
//         return isValidBST(root->left) && isValidBST(root->right);
        
        return help(root,LONG_MAX,LONG_MIN);
        
        
       
        
        
        
        
    }
};
