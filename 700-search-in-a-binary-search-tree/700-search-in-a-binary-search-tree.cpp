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
    
    // bst ki property se sochenge agr val root->val se bdi h to firr ans ya to right mei milega ya ni milega left ka koi scene ni hoga aise hi vice versa
    
    TreeNode* ans;
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;
        
        if(val>root->val) searchBST(root->right,val);
        else if(val<root->val) searchBST(root->left,val);
        else ans=root;
        return ans;
    }
};