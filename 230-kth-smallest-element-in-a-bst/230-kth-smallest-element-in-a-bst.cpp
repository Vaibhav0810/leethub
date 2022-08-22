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
    
    //          BRUTE
    // we can store all elements in an array and then sort the array and return kth element from first
    
    //  optimised
    // first we go to the lowest element in the tree then we increase the count and if count becomes equal to k we return root->val 
//else we go to root->left if it exist
    // Time-o(n) space-0(N)
 
    /*
int count=0;
    int ans=0;
    int kthSmallest(TreeNode* root, int k) {
        
        if(root==NULL) return 0;
        
        return help(root,k);
    }
    
    int help(TreeNode* root,int k){
        
        if(root==NULL) return 0;
        help(root->left,k);
        count++;
        if(count==k){
            ans=root->val;
            return ans;
        }
        else help(root->right,k);
        
        return ans;
        
    }
    */
    //          iterative
    // take a stack and push all left element in it the check ik --k==0 if yes then return st.top()else if st.top() left exist then push it into stack and keep on repeating 
    
    
    
    
    //            MORRIS TRAVERSAL
    // bcz inorder traversal lgg rhi h iss q mei
    // TIME-O(N) space-O(1)
    
    
    int kthSmallest(TreeNode* root,int k){
        if(root==NULL) return 0;
        int count=0;
         int ans=0;
        TreeNode* temp=root;
        while(temp!=NULL){
            if(temp->left==NULL){
                count++;
                if(count==k){
                    ans=temp->val;
                    
                  //  break; why is it giving eroor
                }
                temp=temp->right;
            }
            else{
                TreeNode* prv=temp->left;
                while(prv->right&& prv->right!=temp){
                    prv=prv->right;
                }
                    if(prv->right==NULL){
                        prv->right=temp;
                        temp=temp->left;
                    }
                    else{
                        prv->right=NULL;
                         count++;
                    if(count==k){
                    ans=temp->val;
                        
                    }
                        temp=temp->right;
                    }
                
            }
        }
        return ans;
    } 
    
    
    
};