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

// we make upper bound here and we go to the left and keep on changing upper bound as root->val now when we go right we dont change upper bound and keep it same and then insert right

// in short agr vector ki next value choti h to usse left mei lga do ni to right mei (agr bst ki property ko follow kr rhi h to)

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return help(preorder,i,INT_MAX);
    }
    
    TreeNode* help(vector<int>& preorder,int& i,int bound){
        // if(preorder[i]> bound || i==preorder.size()) yye likhne me isilie error aarha h bcoz agr i size mei bda hoga to ye phle bound se check krega aur vo element array mei h hi ni index exceed kr rha h limit to overflow error dega iislie neeche vala shi h
        if(i==preorder.size() || preorder[i]>bound) return NULL;
        
        TreeNode* root=new TreeNode(preorder[i++]);
        root->left=help(preorder,i,root->val);
        root->right=help(preorder,i,bound);
        return root;
        
    }
    
};