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
    unordered_map<int, vector<int>> adj;
    void makeGraph(TreeNode* root, int parent) {
        if (root == nullptr) return;
        if (parent != -1) {
            adj[root->val].push_back(parent);
        }
        if (root->left) {
            adj[root->val].push_back(root->left->val);
        }
        if (root->right) {
            adj[root->val].push_back(root->right->val);
        }

        makeGraph(root->left, root->val);
        makeGraph(root->right, root->val);
    }

    int amountOfTime(TreeNode* root, int start) {
        // making it to undirected graph
        makeGraph(root, -1);
        int ans = 0;
        set<int> visi;
        queue<int> q;
        q.push(start);
        visi.insert(start);
        while (!q.empty()) {
            int n = q.size();

            while (n--) {
                auto top = q.front();
                q.pop();
                for(auto it:adj[top]){
                    if(visi.find(it)==visi.end()){
                        q.push(it);
                        visi.insert(it);
                    }
                }
            }
            ans++;
        }
        return ans-1;
    }
};