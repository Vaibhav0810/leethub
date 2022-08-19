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
    // Brute Timer-O(N)
   // Space -O(H) bcoz complete tree h to skew ni hoga so N ni ho paayega height ke brabr hi hogi space
    
//     class Solution {
// public:
//     // Brute Time-O(N)
//     // Space- O(N)
//     int count=0;
//     int countNodes(TreeNode* root) {
        
//         if(root==NULL) return 0;
        
//         countNodes(root->left);
//         count++;
//         countNodes(root->right);
        
//         return count;
        
//     }
// };
    
    // optimised Time-O((log N)^2) bcoz tree ki height log N hoti h (so log n for traaversing n log n for height)
    // Space-O(Log N)
    int heightLeft(TreeNode* root){
        int lh=0;
        while(root){
            lh++;
            root=root->left;    
        }
        return lh;
    }
    
    int heightRight(TreeNode* root){
        int rh=0;
        while(root){
            rh++;
            root=root->right;
        }
        return rh;
    }
    
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        
        int lh=heightLeft(root);
        int rh=heightRight(root);
        
        if(lh==rh){
            return pow(2,lh)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
        
        
    }
};