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
//     stack<TreeNode*> st1;
//     stack<TreeNode*> st2;
//     vector<int> ans;
//     vector<int>postorderTraversal(TreeNode* root){
        
//         if(root==NULL) return ans;
        
//         st1.push(root);
//         while(!st1.empty()){
//             st2.push(st1.top());
//             TreeNode*temp=st1.top();
//             st1.pop();
//             if(temp->left!=NULL){
//                 st1.push(temp->left);
//             }
//             if(temp->right!=NULL) st1.push(temp->right);
//         }
        
//         while(!st2.empty()){
//         ans.push_back(st2.top()->val); 
//         st2.pop();
//         }
        
//         return ans;
        
//     }
    
    // Using One stack(video link in notes)
    
    vector<int>postorderTraversal(TreeNode* root){
        stack<TreeNode*>st;
        vector<int>ans;
        TreeNode* curr=root;
        TreeNode* temp;
        while(curr!=NULL ||!st.empty()){
            if(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            else{
                temp=st.top()->right;
                if(temp==NULL){
                    temp=st.top();
                    ans.push_back(st.top()->val);
                    st.pop();
                    while(!st.empty() && temp==st.top()->right){
                        temp=st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else{
                    curr=temp;
                }
                    
            }
        }
        return ans;
    }
    
};