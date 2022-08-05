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
    
    // isme ik curr string bna li h jiss se ans mei as h string sb ik saath push ho 
    // like this pura 1->2->5 aise
    
    
    void help(TreeNode* root,vector<string>&ans,string curr){
        if(root==NULL){
            return;
        }
        
        if(root->left || root->right){
            curr=curr+(to_string(root->val)+"->");
        }
        else{
            curr=curr+(to_string(root->val));
            ans.push_back(curr);
        }
        
        
        help(root->left,ans,curr);
        help(root->right,ans,curr);
        
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string curr="";
        help(root,ans,curr);
        return ans;
    }
};