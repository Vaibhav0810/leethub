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
// class Solution {
// public:
    
//     // recursively
//     vector<int>ans;
//     vector<int> inorderTraversal(TreeNode* root) {
        
//         // think about these cmnts and dry run
        
//         if(!root) return ans;
        
        
//         inorderTraversal(root->left);
        
//         ans.push_back(root->val);
        
//       //  ans.push_back(root->val);
        
//         inorderTraversal(root->right);
//       //  ans.push_back(root->val);
//         return ans;
        
//     }
// };

class Solution {
public:
    stack<TreeNode*>s;
    vector<int>ans;
    vector<int> inorderTraversal(TreeNode* root) {
        
        while(root!=NULL || !s.empty()){
            while(root!=NULL){
            s.push(root);
            root=root->left;
            }
            root=s.top();
            s.pop();
            ans.push_back(root->val);
            root=root->right;
        }
        
        
        return ans;
    }
};