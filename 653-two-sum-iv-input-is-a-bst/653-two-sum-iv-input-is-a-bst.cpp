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
    
    // first we push all elements in vector in sorted order(bst inorder is always sorted) and then we just use 2 pointer 
    // brute force h ye time-O(N) space-O(N)
    
    vector<int> inorder;
    bool findTarget(TreeNode* root, int k) {
        
        helper(root,k);
        
        int i=0;
        int j=inorder.size()-1;
        
        while(i<j){
            if(inorder[i]+inorder[j]==k) return true;
            else if(inorder[i]+inorder[j]<k) i++;
            else if(inorder[i] +inorder[j]>k) j--;
        }
        return false;
    }
    
    vector<int>helper(TreeNode* root,int k){
        if(root==NULL) return inorder;
        helper(root->left,k);
        
        inorder.push_back(root->val);
        helper(root->right,k);
        return inorder;
    }
    
    
    // unordered set se kia h ye
    //iska run time and space upr vale se bht better aa rhi h
    
/*    unordered_set<int>us;
    bool findTarget(TreeNode* root,int k){
        if(root==NULL) return false;
        
        if(us.count(k-root->val)) return true; // us has unique value so when we use count it will check if it has that value present or not the function return 1 if present 0 if not
        // so if hm check kr rhe h k- root->val agr present h us mei to bhadia mtlb ans aagya ni to ye value push kro aur aage niklo bcoz there wont be any duplicates in bst to binakuch check kre kr skte h insert
        us.insert(root->val);
        return findTarget(root->left,k) || findTarget(root->right,k);
        
    }*/
    
    //                                    OPTIMISED SOLUTION
    
 //   bool findTarget(TreeNode* root,int k){
        
 //   }
    
    
    
};