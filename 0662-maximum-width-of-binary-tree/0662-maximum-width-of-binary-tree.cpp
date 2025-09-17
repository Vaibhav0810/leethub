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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        long long ans=0;
        while(!q.empty()){
            int n=q.size();
            long long startIndex=q.front().second;
            long long backIndex = q.back().second;
            ans= max(ans,backIndex-startIndex+1);
            while(n--){
                auto top=q.front();
                q.pop();
                long long idx = top.second-startIndex;   // to prevent signed integer overflow
                if(top.first->left){
                    q.push({top.first->left,2*idx+1});
                }
                if(top.first->right){
                    q.push({top.first->right,2*idx+2});
                }
            }
        }
        return ans;
    }
};