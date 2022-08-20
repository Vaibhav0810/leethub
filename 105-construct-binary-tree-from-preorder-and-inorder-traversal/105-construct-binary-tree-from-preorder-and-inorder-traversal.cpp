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
// ye iteratively try kr rha tha mai
// dekhte h kaise hoga
//         TreeNode* temp=new TreeNode();
        
//         queue<int>q;
//         q.push(preorder[0]);
//         while(!q.empty()){
//         temp->val=q.front();
//         q.pop();
        
//         int store=0;
//         int i=0;
//         for(int i=0;i<inorder.size();i++){
//             if(preorder[0]!=inorder[i])
//             store++;
        
//         else break;
//         }
//         i=1;
//         while(store--){
//             q.push(preorder[i]);
//         }
        
//         temp=temp->left;
        
//         }

// recursion TIme-O(N)
//Space-O(N);

// phle isme map mei inorder ki sari value push krenge uske index ko point krke(unordered map bhi le skte h)
// then helper function mei index mtlb jo vo root h uska index kya h inorder mei map mei
// num left mtlb left mei kitne element bche h

class Solution{
    public:
    
    
    TreeNode* buildTree(vector<int> &preorder,vector<int> &inorder){
        map<int,int>inM;
        
        for(int i=0;i<inorder.size();i++){
            inM[inorder[i]]=i;
        }
        
        TreeNode* root=help(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inM);
        
        
        return root;
        
    }
    
    TreeNode* help(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,map<int,int>&inM){
        
        if(preStart>preEnd || inStart>inEnd) return NULL;
        
        TreeNode* root=new TreeNode(preorder[preStart]);
        
        int index=inM[root->val];
        int numLeft=index-inStart;
        
        root->left=help(preorder,preStart+1,preStart+numLeft,inorder,inStart,index-1,inM);
        root->right=help(preorder,preStart+numLeft+1,preEnd,inorder,index+1,inEnd,inM);
            
            return root;
    }
    
};