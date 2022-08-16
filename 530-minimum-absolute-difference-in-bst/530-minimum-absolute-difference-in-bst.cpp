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
 
// isme phle maine ik vector bnakr usme push krna chaha but first second ke bdd aur push ni hua upr se bht space and time comp lee rha h so not a good solution
class Solution {
public:
    int mmin=INT_MAX;
    
    int getD(TreeNode* root){
        if(root==NULL) return 0;
        
        int lh=getD(root->left);
        int rh=getD(root->right);
        
        return 1+max(lh,rh);
        
    }
    
    int getMinimumDifference(TreeNode* root) {
        
        if(root==NULL) return 0;
        
        vector<int>v;
        
        v.push_back(root->val);
        cout<<getD(root)<<endl;
        int n=getD(root)-1;
        while(n>0){
            if(root->left) v.push_back(root->left->val);
            if(root->right) v.push_back(root->right->val);
            n--;
        }
        for(int i=0;i<v.size()-1;i++){
            for(int j=i+1;j<v.size();j++){
                if(abs(v[i]-v[j])<mmin){
                    mmin=abs(v[i]-v[j]);
                }
            }
        }
        return mmin;
    }
};


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


class Solution{
    public:
    
    int diff=INT_MAX;
    TreeNode*prv=NULL;
    void help(TreeNode*root){
        if(root->left) help(root->left);
        
        if(prv) diff=min(diff,root->val-prv->val);
        prv=root;
        
        if(root->right) help(root->right);
    }
    
    int getMinimumDifference(TreeNode* root){
        if(root==NULL) return 0;
        
        
        help(root);
        return diff;
    }
};

