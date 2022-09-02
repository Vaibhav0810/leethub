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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<double>ans;
        while(!q.empty()){
            int n=q.size();
            vector<int>avg;
            for(int i=0;i<n;i++){
                
                auto x= q.front();
                q.pop();
                avg.push_back(x->val);
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            double a=0;
            double sum=0;
            for(int i=0;i<avg.size();i++){
                sum=sum+avg[i];
            }
            a=sum/avg.size();
            ans.push_back(a);
            
        }
    
    return ans;
    }
};