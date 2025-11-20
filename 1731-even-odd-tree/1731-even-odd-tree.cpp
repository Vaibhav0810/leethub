/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        // do bfs
        // int level = 0;
        bool even = true;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int prv=-1,curr;
            // prv = q.front()->val;
            while (n--) {
                auto top = q.front();
                q.pop();
                curr = top->val; 
                if(even){
                    if(prv!=-1){
                        if(prv>=curr) return false;    
                    }
                    if(curr%2==0) return false;
                }
                else{
                    if(prv!=-1) if(prv<=curr) return false;
                    if(curr%2!=0) return false;
                }
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
                prv= top->val;
                
            }
            even=!even;
        }
        return true;
    }
};