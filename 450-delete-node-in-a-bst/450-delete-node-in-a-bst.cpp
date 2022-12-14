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
    
    // first check if where is the key value find it in tree when found
    // now if its on root itself we need to join root->left and root->right using help function
    // if its on right or left so we combine root->left with root->right ke rightmost element se
    // and then we return roots ->left
    // TIME-O(height of tree) SPACE-none
    
    TreeNode* deleteNode(TreeNode* temp,int key){
        
        if(temp==NULL) return NULL;
        TreeNode* root=temp;
        
        if(root->val==key){
            return help(root);
        }
        
        while(root){
            if(root->val>key){
                if(root->left && root->left->val==key){
                    root->left=help(root->left);
                }
                else{
                root=root->left;
                }
            }
            else{
                if(root->right && root->right->val==key){
                    root->right=help(root->right);
                }
                else{
                    root=root->right;
                }
            }
        }
        return temp;
    }
    
    TreeNode* help(TreeNode* root){
        
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;
        
        TreeNode* rightchild=root->right;
        
        TreeNode* rightmost=findright(root->left);
        rightmost->right=rightchild;
        return root->left;
    }
    
    TreeNode* findright(TreeNode* root){
        
        if(root->right==NULL) return root;
        return findright(root->right);
        
    }
    
};