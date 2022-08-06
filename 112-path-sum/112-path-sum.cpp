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
    
    // iss code mei phli dikkt to ye h hum sum ko 0 kr rhe h initilize so agr 
    // root to leaf mei 0 ni bhi h to bhi targetsum agr 0 h to true return kr dega ye(case(0))
    // aur bhi dikkt h
    
//     int sum=0;
//     bool hasPathSum(TreeNode* root, int targetSum){
        
//         if(root==NULL){
            
//             return 0;
//         }
//            case (0);
//         if(targetSum==0 && root->val!=0){
//             return false;
//         }
        
//         if(sum==targetSum )
//         return true;
       
        
//         if(sum+root->val>targetSum){
//             return 0;
//         }
//         else{
//             sum=sum+root->val;
//         }
//         //cout<<sum<<" ";
//         return hasPathSum(root->left,targetSum)||hasPathSum(root->right,targetSum);
           
            
        bool hasPathSum(TreeNode* root, int sum){
            
            if(root==NULL){
                return 0;
            }
            // ye iislie check kr rhe h null bcoz leaf node tk ka path chahie ho ske beech mei pura hojaye to vo correct ni h
            if(root->val==sum && root->left==NULL && root->right==NULL) return true;
            
            return hasPathSum(root->left,sum-root->val)|| hasPathSum(root->right,sum-root->val);
            
        
        
        
    }
};