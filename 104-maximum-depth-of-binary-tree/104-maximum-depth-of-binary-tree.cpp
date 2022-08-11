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
   /* 
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        
        return 1+max(maxDepth(root->left),maxDepth(root->right));
        
    }
    */
    
    // ITERATIVELY

    int maxDepth(TreeNode* root){
        if(root==NULL) return 0;
        int d=0;
        queue<TreeNode*>q;   
        q.push(root);
        while(!q.empty()){
        d++;
        int n=q.size();
        for(int i=0;i<n;i++){
        
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        
            
        }
        }
        return d;
    }
};