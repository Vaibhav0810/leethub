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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL) return {};
        map<int,multiset<pair<int,int>>>mp;
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});

        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto curr=q.front();
                q.pop();
                mp[curr.second.second].insert({curr.second.first,curr.first->val});
                if(curr.first->left){
                    q.push({curr.first->left,{curr.second.first+1,curr.second.second-1}});
                }
                if(curr.first->right){
                    q.push({curr.first->right,{curr.second.first+1,curr.second.second+1}});
                }
            }
        }

        for(auto &[x,st]:mp){
            ans.push_back({});
            for(auto &[idx,node]:st){
               ans.back().push_back(node); 
            }
        }


        return ans;
    }
};