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
    // bool check=true;
    bool help(TreeNode* p,TreeNode* q){
        
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
       
       
        if(p->val!=q->val){
            
            return false;
            
        }
        return help(p->left,q->left)&&help(p->right,q->right);
         
        //return check;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
         return help(p,q);
    }
};