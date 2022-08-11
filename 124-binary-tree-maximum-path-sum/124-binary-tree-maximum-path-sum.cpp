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
   
    // help function mei return tu function ki help ke lie kr rha h ki usse aage kya chhaie hoga left and
    // right pr traverse krne ke bdd
    // aur maxi store tu apne ans ke lie kr rha h
   
    int help(TreeNode* root,int &maxi){
        if(root==NULL) return 0;
        
        int l=max(0,help(root->left,maxi));
        int r=max(0,help(root->right,maxi)); // aise krne se -ve vali hrkt khtm ho jaayegi usse dekhega hi ni ye code 
        // ye dekhna h ki agr right left se -ve aa rha h to usse consider hi ni krenge kyoki vo max ni hoga
        
        
        maxi=max(maxi,l+r+root->val);
  
        
        return (root->val)+max(l,r);
    }
    
    int maxPathSum(TreeNode* root) {
         int maxi=INT_MIN;
        help(root,maxi);
        return maxi;
    }
};