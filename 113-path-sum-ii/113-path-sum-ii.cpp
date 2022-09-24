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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        
        vector<vector<int>>ans;
        
        if(root==NULL) return ans;
        vector<int>v;
        help(root,targetSum,v,ans);
        //ans.push_back(v);
        return ans;
        
    }
    
    void help(TreeNode* root,int target,vector<int>v,vector<vector<int>>&ans){
        
        if(root==NULL) return  ;
        
        
        
        target=target-root->val;
        v.push_back(root->val);
        
        if(target==0 && root->left==NULL && root->right==NULL){
            ans.push_back(v);
            return;
        }
        
        help(root->left,target,v,ans);
        help(root->right,target,v,ans);
        
    }
    
};