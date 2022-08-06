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
    int sum=0;
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
         
        // isme hm dekkh rhe h phle agr root ka koi left h?
        // agr h to theek h vo check kro vo leaf h ya ni h to sum mei add ni to return
        if(root->left && root->left->right==NULL && !root->left->left)
            sum=sum+root->left->val;
        
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        
      
        return sum;
        
    }
};