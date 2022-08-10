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
    // Time-O(N) Space -O(N)()
 /*   vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        // left right root (bcoz post that is root in ppost i.e.in end)
        
        if(root==NULL) return ans;
        
        postorderTraversal(root->left);
        
        postorderTraversal(root->right);
        ans.push_back(root->val);
        
        return ans;
        
    }
    */
    
    // USING 2 STACKS
    // Time-O(N) Space-O(2N)
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    vector<int> ans;
    vector<int>postorderTraversal(TreeNode* root){
        
        if(root==NULL) return ans;
        
        st1.push(root);
        while(!st1.empty()){
            st2.push(st1.top());
            TreeNode*temp=st1.top();
            st1.pop();
            if(temp->left!=NULL){
                st1.push(temp->left);
            }
            if(temp->right!=NULL) st1.push(temp->right);
        }
        
        while(!st2.empty()){
        ans.push_back(st2.top()->val); 
        st2.pop();
        }
        
        return ans;
        
    }
};