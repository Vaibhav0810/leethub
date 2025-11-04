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
    bool traverse(TreeNode* &root){
        if(root==NULL) return false;
        
        bool store1 = traverse(root->left);
        bool store2 =traverse(root->right);
        if(root->val==0 && !store1 && !store2){
            root=NULL;
            return false;
        }
        if(root->val==1) return true;
        return store1||store2;
    }

    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL) return NULL;
        traverse(root);
        return root;
    }
};