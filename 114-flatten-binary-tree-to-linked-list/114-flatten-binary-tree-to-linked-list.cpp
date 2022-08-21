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
    
    // recursive 
    //TIME -O(N) SPACE-O(N)
    /*
    TreeNode* temp;
    void flatten(TreeNode* root) {
        
        if(root==NULL) return;
        
        flatten(root->right);
        flatten(root->left);
        
        
        root->right=temp;
        root->left=NULL;
        temp=root;
        
    }
    */
    
    // stack based (iterative)
    //time-O(N) space-O(N)
    
/*    void flatten (TreeNode* root){
        stack<TreeNode*>st;
        if(root==NULL) return;
        st.push(root);
        
        while(!st.empty()){
            TreeNode* temp=st.top();
            st.pop();
            
            if(temp->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);
            
            
            if(!st.empty()){
                temp->right=st.top();
            }
            temp->left=NULL;
        }
        
    }
    */
    
    // Morris Traversal 
    // space-o(1) time-o(n)
    
    // in this we will make a thread b/w root left subttree ke right most element and root-> right pr 
    
    void flatten(TreeNode* root){ 
        if(root==NULL)return ;
        
        TreeNode* temp=root;
        
        while(temp){
            if(temp->left!=NULL){
                
                TreeNode* prv=temp->left;
                
                while(prv->right){
                    prv=prv->right;
                }
                 prv->right=temp->right;
                temp->right=temp->left;
                temp->left=NULL;
                
               
            }
            temp=temp->right;
        }
        
    }
    
};