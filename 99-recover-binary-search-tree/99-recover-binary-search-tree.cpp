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
    
    // first we take a vector and then push inorder traversal of binaryst in it and then we sort the array
    // and then we again traverse over the tree making the tree value equal to v[0] and removing element from the front of vector
    // Time-o(nlog n)+o(n)+o(n)(for sorting, for traversal 2 times) space-O(N)
    // iskko thda sa optime krskte h jiss se sorting ka n log n ht jayega sirf O(N) rhega
    // we make 2 pointer i pointing to start element and j ppointing to end element
    // if i is smaller insert it in tree and then i++ if jis smaller then insert it in tree and j--
    /*
    vector<int> v;
    void recoverTree(TreeNode* root) {
        
        help(root);
        sort(v.begin(),v.end());
        
        ans(root);
        
    }
    
    void ans(TreeNode* root){
        if(root==NULL) return;
        ans(root->left);
        root->val=v[0];
        v.erase(v.begin());
        ans(root->right);
    }
    
    void help(TreeNode* root){
        if(root==NULL) return;
        
        help(root->left);
        v.push_back(root->val);
        help(root->right);
        
    }
    */
    
    //      optimised
    // TIME-O(N) Space-O(1)(if recruiter say we can ignore recursion stack but if he says u cant they tell him about morris traversal)
    
    // if this tree has not been swappped then inorder would be in sorted order but now this is not the case 
    // so we will take the inorder and check where this condition is broken when we found root->val <prv->val we store them and then we swap them
    // now two case arises when the value to be swapped are adjacent like
    // 1 3 2 4 (eg2)
    // in this we will store first element as 3 and middle element as 2 and now there wont be any last element so we swap first and middle
    // but in this case 
    //1 2 3 4 8 6 7 5 9
    // in this we will be able to store first middle and last and the we check if last exist we swap first and last
    // else we swap first and middle
    
    TreeNode* first,*middle,*last,*prv;
    void inorder(TreeNode* root){
        
        if(root==NULL) return;
        
        inorder(root->left);
        if(prv!=NULL && root->val<prv->val){
            
            if(first==NULL){
                first=prv;
                middle=root;
            }
            else{
                last=root;
            }
            
        }
        prv=root;
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root){
        first=middle=last=NULL;
        prv=new TreeNode(INT_MIN);
        inorder(root);
        if(first&& last) swap(first->val,last->val);
        else if(first && middle)swap(first->val,middle->val);
        
    }
    
};