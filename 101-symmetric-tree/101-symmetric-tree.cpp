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
    // iislie vector vala method use ni kr skte bcoz of this eg
    
          //    1
          // 2      2
          //  3       3
    // bcoz ye to hmare logic se shi ans hi dega
    // so think diff logic
  /*  
    queue<TreeNode*>q;
    bool check=false;
    bool help(TreeNode* root){
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            int n=q.size();
            q.pop();
            vector<int>v;
            for(int i=0;i<n;i++){
                v.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            int m=v.size();
            for(int i=0;i<m;i++){
                if(v[i]==v[m-i-1]){
                    check=true;
                }
                else { 
                check=false;      
                return false;
                }
            }
            if(check==false) return false;
            
        }
        return check;
        
    }
    
    bool isSymmetric(TreeNode* root) {
        return help(root);
    }
    */
    // 2 option h ya to 2 queue bna le ya 2 pointer 2 pointer jyada space efficient h
    /*
    bool isSymmetric(TreeNode* root){
        if(!root) return true;
        queue<TreeNode*>q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode* temp1=q.front();
            q.pop();
            TreeNode* temp2=q.front();
            q.pop();
             if(temp1 &&!temp2) return false;
             if(!temp1 && temp2) return false;
           // if(temp1==NULL || temp2==NULL) return false; // ye nii chl rha
            if(temp1 && temp2){
            if(temp1->val!=temp2->val) return false;
            
                q.push(temp1->left);
                q.push(temp2->right);
                q.push(temp1->right);
                q.push(temp2->left);
            
            }
        }
        return true;
    }
    */
    // recursive
    
    bool help(TreeNode* left,TreeNode* right){
        if(left==NULL && right==NULL) return true;
        if(!left|| !right) return false;
        
        if(left->val!=right->val){
            return false;
        }
        else{
            return help(left->left,right->right)&& help(left->right,right->left);
        }
        
    }
    bool isSymmetric(TreeNode* root){
        return help(root->left,root->right);
    }
    
};