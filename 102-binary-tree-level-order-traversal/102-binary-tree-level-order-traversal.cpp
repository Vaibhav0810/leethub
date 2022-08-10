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

/*
    phle ik queue bnayenge aur usme root daalenge 
    ab q ke size ko n mei store kr lenge aur firr loop lgakr check krenge ki q.front ka left and right h to ni
    aur agr h to usse q mei dall te rhenge 
    end mei temp ki val v mei store krke ans mei daal denge n ans return
*/

class Solution {
public:
    
    
   
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        
         queue<TreeNode*>q;
        if(root==NULL) return ans;
        
        q.push(root);
            
        while(!q.empty()){
            int n=q.size();
            vector<int>v;
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
            if(temp->left!=NULL){
                q.push(temp->left);
                
            }
            
            if(temp->right!=NULL){
                q.push(temp->right);
                
            }
                v.push_back(temp->val);
            }
            
            
            ans.push_back(v);
            
            
        }
        return ans;
    }
};