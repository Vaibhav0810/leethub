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
 


// another appraoch (recursive)
// ye bhi glt h(bcoz isme ye sirf aaspass ki value pr dekh rha h)
// iss vale test case mei glt ho jaayega ye [236,104,701,null,227,null,911]

class Solution{
    public:
    int mmin=INT_MAX;
    
    int help(TreeNode* root,int prv){
        if(root==NULL) return 0;
        prv=root->val;
        if(root->left && root->right){
            int s=min(abs(root->left->val-prv),abs(root->right->val-prv));
            mmin=min(mmin,s);
        }
        if(root->right==NULL && root->left!=NULL){
            mmin=min(mmin,abs(root->left->val-prv)); 
        }
        if(root->left==NULL && root->right!=NULL){
            mmin=min(mmin,abs(root->right->val-prv)); 
        }
        help(root->left,root->val);
        help(root->right,root->val);
        return mmin;
    }
    
    int getMinimumDifference(TreeNode* root){
        if(root==NULL) return 0;
        return help(root,root->val);
    }
    
};
*/

//  CORRECT SO;UTION
// jaise hme array mei agr aise absolute diff nikalna ho to kya krenge phle array sort krenge then closest value ka diff ka min nikalnege same aise hi iss mei
// inorder travsersal se tree sort ho gya aur iik oprv maintain krenge jo uss se phle point krega so unn dono ko sub krenge aur jo min aaye vo ans
          BRUTE
class Solution {
public:
    vector<int> ans;
    int diff=INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        
        help(root);
        for(int i=0;i<ans.size()-1;i++){
            diff=min(diff,ans[i+1]-ans[i]);
        }
        return diff;
    }
    
    int help(TreeNode* root){
       if(root==NULL) return 0;
        
        help(root->left);
        ans.push_back(root->val);
        help(root->right);
         return 0;
    }
    
};

                          OPTIMISED

class Solution{
    public:
    
    int diff=INT_MAX;
    TreeNode*prv=NULL;
    void help(TreeNode*root){
        if(root->left) help(root->left);
        
        if(prv) diff=min(diff,root->val-prv->val);
        prv=root;
        // ye jo neeche vala if h ye isilie h bcoz if(root==NULL) return ni likha vo likho ya ye ik hi baat h
        if(root->right) help(root->right);
    }
    
    int getMinimumDifference(TreeNode* root){
        if(root==NULL) return 0;
        
        
        help(root);
        return diff;
    }
};

