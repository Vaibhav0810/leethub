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
    
    // first we take a vector and then push inorder traversal of binaryst in it and then we sort the array
    // and then we again traverse over the tree making the tree value equal to v[0] and removing element from the front of vector
    // Time-o(nlog n)+o(n)+o(n)(for sorting, for traversal 2 times) space-O(N)
    vector<int> v;
    void recoverTree(TreeNode* root) {
        
        help(root);
        sort(v.begin(),v.end());
        
        ans(root);
        
    }
    
    void ans(TreeNode* root){
        if(root==NULL) return;
        ans(root->left);
        root->val=v[0];
        v.erase(v.begin());
        ans(root->right);
    }
    
    void help(TreeNode* root){
        if(root==NULL) return;
        
        help(root->left);
        v.push_back(root->val);
        help(root->right);
        
    }
};