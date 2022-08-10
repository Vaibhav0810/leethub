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
    // TIME-O(N) 
    //SPACE-O(N) (in worst case i.e. skew trees)
 /*   vector<int>ans;
    vector<int> preorderTraversal(TreeNode* root) {
        //root l r
        
        if(root==NULL) return ans;
        
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        
        return ans;
        
    }
    */
    // ITERATIVELY
    // same time and space comp
    stack<TreeNode*>st;
    vector<int> ans;
    vector<int>preorderTraversal(TreeNode* root){
        if(root==NULL) return ans;
        
        st.push(root);
        
        
        while(!st.empty()){
            TreeNode* check=st.top();
            ans.push_back(st.top()->val);
            st.pop();
            
            if(check->right!=NULL){
                st.push(check->right);
            }
            if(check->left!=NULL){
                st.push(check->left);
            }
            
        }
        return ans;
    }
};