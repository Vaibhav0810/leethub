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
    // THIS AINT WORKING
/*class BSTIterator {
    vector<TreeNode*>ans;
public:
    
   
    
    BSTIterator(TreeNode* temp) {
        //TreeNode*temp=root;
        
        help(temp);
    }
    
    
    vector<TreeNode*> help(TreeNode* temp){
        
        if(temp==NULL) return ans;
        
        help(temp->left);
        ans.push_back(temp);
        help(temp->right);
        return ans;
    }
    int next() {
        int x=ans.front()->val;
        ans.erase(ans.begin());
        return x;
    }
    
    bool hasNext() {
        if(ans.size()!=0) return true;
        else return false;
    }
};
*/

class BSTIterator {
    stack<TreeNode*>st;
public:
    
   
    
    BSTIterator(TreeNode* root) {
        //
        
        help(root);
    }
    
    
    void help(TreeNode* root){
        TreeNode*temp=root;
      
        
        while(temp!=NULL){
            st.push(temp);
            temp=temp->left;
        }
        
    }
    int next() {
        TreeNode* x=st.top();
        st.pop();
        if(x->right!=NULL){
            help(x->right);
        }
        return x->val;
    }
    
    bool hasNext() {
        if(st.size()!=0) return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */