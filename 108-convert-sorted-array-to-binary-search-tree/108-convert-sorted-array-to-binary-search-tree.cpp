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
    // binary search lgai h ye
    TreeNode* help(vector<int>& nums,int low,int high){
        
        if(low>high)
            return NULL;
        int mid=(low+high)/2;
        TreeNode* balanced=new TreeNode();
        balanced->val=nums[mid];
        balanced->left=help(nums,low,mid-1);
        balanced->right=help(nums,mid+1,high);
        return balanced;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        
        
        if(nums.size()==0){
            return 0;
        }
        
        return help(nums,0,nums.size()-1);
        
        
        
    }
};