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
// class Solution {
// public:
    
//     // recursively
        //TIME-O(N) SPACE-O(N) (WORST CASE)
        // IN avg case space = O(logn)
//     vector<int>ans;
//     vector<int> inorderTraversal(TreeNode* root) {
        
//         // think about these cmnts and dry run
        
//         if(!root) return ans;
        
        
//         inorderTraversal(root->left);
        
//         ans.push_back(root->val);
        
//       //  ans.push_back(root->val);
        
//         inorderTraversal(root->right);
//       //  ans.push_back(root->val);
//         return ans;
        
//     }
// };

                            // ITERATIVE USING STACK 
    //TIME-O(N) SPACE-O(N)
    // isme ik stack lenge phle firr usme push krte rhenge left aur jb left  khali ho jayega
    // tb root=s.top krke root->val ko ans array mei daalkr right pr call kr denge

/*class Solution {
public:
    stack<TreeNode*>s;
    vector<int>ans;
    vector<int> inorderTraversal(TreeNode* root) {
        
        while(root!=NULL || !s.empty()){
            while(root!=NULL){
            s.push(root);
            root=root->left;
            }
            root=s.top();
            s.pop();
            ans.push_back(root->val);
            root=root->right;
        }
        
        
        return ans;
    }
};
*/
//                                    MORRIS TRAVERSAL
// TIME-O(N) SPACE-O(1)

//\U0001f333 1st case: if left is null, print current node and go right
//\U0001f333 2nd case: before going left, make right most node on left subtree connected to current node, then go left
//\U0001f333 3rd case: if thread is already pointed to current node, then remove the thread

class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        TreeNode* temp=root;
        
        while(temp!=NULL){
            if(temp->left==NULL){
                ans.push_back(temp->val);
                temp=temp->right;
            }
            else{
                TreeNode* prev=temp->left;
                while(prev->right!=temp && prev->right){
                        prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=temp;
                    temp=temp->left;
                }
                else{
                    prev->right=NULL;
                    ans.push_back(temp->val);
                    temp=temp->right;
                }
                    
            }
        }
        return ans;
    }
};
