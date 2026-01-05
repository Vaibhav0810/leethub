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
    // int findMax(vector<int>& nums, int st, int end) {
    //     // return 0;
    //     int maxi = INT_MIN;
    //     int idx = -1;
    //     for (int i = st; i <= end; i++) {
    //         // maxi= max(maxi,nums[i]);
    //         if (maxi < nums[i]) {
    //             maxi = nums[i];
    //             idx = i;
    //         }
    //     }
    //     return idx;
    // }

    // TreeNode* buildTree(vector<int>& nums, int st, int end) {
    //     if (st > end) return NULL;
    //     int store = findMax(nums, st, end);
    //     TreeNode* head = new TreeNode(nums[store]);
    //     // head->left = new TreeNode(constructMaximumBinaryTree(nums));
    //     head->left = buildTree(nums, st, store - 1);
    //     head->right = buildTree(nums, store + 1, end);
    //     return head;
    // }
    // TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    //     if (nums.size() == 1)
    //         return new TreeNode(nums[0]);
    //     return buildTree(nums, 0, nums.size() - 1);
    //     // return NULL;
    // }

    // using stack
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 1)
            return new TreeNode(nums[0]);
        
        vector<TreeNode*>st;

        for(int i=0;i<nums.size();i++){
            TreeNode* curr = new TreeNode(nums[i]);
            while(!st.empty() && st.back()->val<nums[i]){
                curr->left=st.back();
                st.pop_back();
            }
            if(!st.empty())
            st.back()->right = curr;

            st.push_back(curr);
        }
        return st.front();

    }
};