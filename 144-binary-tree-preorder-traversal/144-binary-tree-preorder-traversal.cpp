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

    /*stack<TreeNode*>st;
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
*/
    //Morris Traversal
    // TIME-O(N) SPACE-O(N)
    
    // ISME hm left subtree ke right most element ko uss subtree ke root se connect kr denge 
    // like 1 2 6 3 4 isme 4 ko 1 se connect and then 3 ko 2 se connect aise;
    // aur jb connection already bna hua h to usse vps null krdenge vrna loop sa bnn jaayenge never ending
    
    // edge cases
    // if left == null push value in vector and traverse to right
    // if right==NULL right = curr
    // if right == curr then right becomes NULL
    
        vector<int>preorderTraversal(TreeNode* root){
            vector<int> preorder;
            
            TreeNode* temp=root;
            while(temp){
                if(temp->left==NULL){
                    preorder.push_back(temp->val);
                    temp=temp->right;
                }
                else{
                    TreeNode* prv=temp->left;
                    while(prv->right && prv->right!=temp){
                        prv=prv->right;
                    }
                    if(prv->right==NULL){
                        preorder.push_back(temp->val);
                        prv->right=temp;
                        temp=temp->left;
                    }
                    else{
                        prv->right=NULL;
                        temp=temp->right;
                    }
                }
            }
            return preorder;
        }
    };