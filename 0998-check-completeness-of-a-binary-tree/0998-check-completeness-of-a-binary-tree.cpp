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
    bool isCompleteTree(TreeNode* root) {
        bool check =false;
        queue<TreeNode*>q;
        if(root==NULL) return true;
        q.push(root);
        while(!q.empty()){
            auto top = q.front();
            q.pop();

            

            if(check==true && (top->left || top->right) ){
                return false;
            }
            if(top->left && top->right){
                q.push(top->left);
                q.push(top->right);
            }
            else if(top->left && !top->right){
                q.push(top->left);
                check = true;
            }
            else if(!top->left && top->right){
                return false;
            }
            else check = true; 
        }
        return true;
    }
};