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
 

class Solution {
public:
    
    bool help(TreeNode* left,TreeNode* right){
         if(left==NULL && right==NULL)   return true;
        if(left==NULL || right==NULL)   return false;
        if(left->val!=right->val){
            return false;
        }
        else{
            return help(left->left,right->right)&& help(left->right,right->left);
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL) return 0;
        return help(root->left,root->right);
        
    }
};
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*>q1;
        queue<TreeNode*>q2;
        
        q1.push(root->left);
        q2.push(root->right);
        
        while(!q1.empty() && !q2.empty()){
            TreeNode* left=q1.front();
            TreeNode* right=q2.front();
            q1.pop();
            q2.pop();
            
            if(left==NULL && right==NULL) continue;
            else if(left==NULL || right==NULL) return false;
            else if(left->val !=right->val) return false;
            
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
            
        }
        return true;
    }
    
    /*
                        USING ONE STACK(JAVA CODE)
public boolean isSymmetric(TreeNode root) {
  if (root == null) {
    return true;
  }
  if (root.left == null && root.right == null) return true;
  if (root.left == null || root.right == null) return false;
  // children are not null
  Stack<TreeNode> stack = new Stack<>();
  stack.push(root.left);
  stack.push(root.right);
  
  while (stack.size() > 0) {
    TreeNode t1 = stack.pop();
    TreeNode t2 = stack.pop();
    // null check
    if (t1 == null && t2 == null) continue;
    if (t1 == null || t2 == null) return false;
    // value check
    if (t1.val != t2.val) return false;
    // push children
    stack.push(t1.right); stack.push(t2.left); // could be null
    stack.push(t1.left); stack.push(t2.right);
  }
  
  return true;
}
    */
    
};