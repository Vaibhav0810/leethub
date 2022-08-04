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
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        if(root==NULL){
            return 0;
        }
        
        rangeSumBST(root->left,low,high);
        rangeSumBST(root->right,low,high);
        if(root->val>=low && root->val<=high)
            sum=sum+root->val;
        
   // iss line ko if se upr neeche kbhi bhi lga skte h
        // rangeSumBST(root->left,low,high); iss vali ko
       
        
        return sum;
        
    }
};