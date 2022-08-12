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

/* 
    use level order traversal and maintain a secondary vector named v and after loop end push the final element of v
    in ans vector


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            
            int n=q.size();
            
            vector<int>v;
            
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                v.push_back(temp->val);
            }
            int x=v.size()-1;       // storing last element
            ans.push_back(v[x]);    // pushing last element of v in ans
        }
        return ans;
    }
};
*/

// ik aur kaam kr skte h v ke nye vector ki jgh ussi mei compare krle agr i==n-1 then push in ans
/*
Time-O(N)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            
            int n=q.size();
            
            
            
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                if(i==n-1) ans.push_back(temp->val);
            }
            
        }
        return ans;
    }
};
*/
 //       Recursive(reverse pre order)
//Time-O(N) space -O(N)
class Solution {
public:
    vector<int> ans;
    void help(TreeNode*root,int level,vector<int>&ans){
        if(root==NULL) return ;
        
        if(ans.size()==level) ans.push_back(root->val);
        help(root->right,level+1,ans);
        help(root->left,level+1,ans);
        
    }
    vector<int> rightSideView(TreeNode* root){
        vector<int> ans;
        help(root,0,ans);
        return ans;
    }
};


