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
   // Time and space=O(N)
    // isme ye ho rha h phle  agr dono root null h to null return krdo
    // agr ik null h to opposite return krdo
    // now root1 mei root1+root2 daalenghe
    // but jb root1 null hoga ye uddhr ni jaayega agr aise krenge to
    //mergeTrees(root1->left,root2->left);(sirf aise krenge to ni hoga)
    //bcoz vo null h udhr jaakr retuyrn kr dega
    // isilie hm root1 ke left ya right ko uske eq krenge jiss se agr udhr null bhi ho to kuch bnn jaaye udhr
    // 
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) return NULL;
         if(root1==NULL) {
             
             return root2;
         }
         if(root2==NULL) {
             return root1;
         }
        
        root1->val=root1->val+root2->val;
        root1->left=mergeTrees(root1->left,root2->left);
        root1->right=mergeTrees(root1->right,root2->right);
        return root1;
    }
};