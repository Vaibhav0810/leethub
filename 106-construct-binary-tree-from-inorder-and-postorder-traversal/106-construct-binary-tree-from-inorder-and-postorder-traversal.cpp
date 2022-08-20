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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        map<int,int>inM;
        
        for(int i=0;i<inorder.size();i++){
            inM[inorder[i]]=i;
        }
        
        return help(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,inM);
        
    }
    
    TreeNode* help(vector<int>& inorder,int inStart,int inEnd,vector<int>& postorder,int pStart,int pEnd,map<int,int>&inM){
        
        if(inStart>inEnd || pStart>pEnd) return NULL;
        
        TreeNode* root=new TreeNode(postorder[pEnd]);
        
        int index=inM[root->val];
        int numLeft=index-inStart;
        
        root->left=help(inorder,inStart,index-1,postorder,pStart,pStart+numLeft-1,inM);
        root->right=help(inorder,index+1,inEnd,postorder,pStart+numLeft,pEnd-1,inM); 
        
            
        return root;
        
    }
    
};