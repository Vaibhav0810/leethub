/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
    isme phle 2-3 condition dekhni h 
    1. if root==p ya q ho jaata h to mtlb uske aage jaane ki jroort ni h ans vo hoga ya uss se phle
    2. agr return krte hue root ke left right se null ni aa rha dono se to vo root hi ans h
    3. agr kisi bhi ik jgh se null aa rha h to uska opposite return krdo
    like agr left se null aarha h to right return aise
    (bcoz jb upr aarhe the vps return krke to ik left aarha h pass aur ik right soagr koi bhi null h to uska opposite chahie hme)
    aur agr koi bhi null ni h to vohi root ans h
    
*/

    // TIME -O(N) SPACE-O(N)(WORST CASE(which happen in case of skew trees))
    // skew trees mtlb jinke sare node ik hi side ik hi line mei hote h
// A skewed binary tree is a type of binary tree in which all the nodes have only either one child or no child.

class Solution {
public:
  
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
    if(root==NULL) return NULL;
    if(root==p || root==q) return root; 
        
         TreeNode* left=lowestCommonAncestor(root->left,p,q);
         TreeNode* right=lowestCommonAncestor(root->right,p,q);
        
        if(left!=NULL && right!=NULL) return root;
        if(left!=NULL && right==NULL) return left;
            else return right;
        
        
    }  
};