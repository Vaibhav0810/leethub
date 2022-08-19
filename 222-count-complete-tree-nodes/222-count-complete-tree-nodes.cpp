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
    
    // isme hm jb tk aage jaate rhenge jb tk left n right height equal na mile jaise hi milegi hm uska ans return kr denge and end mei root node + kr denge
//     Self Notes:
// 🍇 Formula is (2^TreeLevel - 1). Only works for perfect tree.
// 🍇 To determine if its a perfect tree, go all the way down and count the nodes on left and right side, If they match, its a perfect tree and our formula applies.
// 🍇 If its not a perfect tree, we go on left and right subtree and again determine if they are perfect tree.
// 🍇 When we have our left and right heights, we do (1 + left + right)
// 🍇 If we reach null, return 0
// 🍇 C++ note: 1 << n is the same as raising 2 to the power n, or 2^n
    
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
            return pow(2,lh)-1; // bcoz agr both sides ki height ewual ho to total itni hi nodes hoti h formula h
        }
        return 1+countNodes(root->left)+countNodes(root->right);
        
        
    }
};
