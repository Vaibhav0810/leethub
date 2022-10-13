/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // recursive
    // vector<int> preorder(Node* root) {
    //     vector<int>ans;
    //     help(root,ans);
    //     return ans;
    // }
    // void help(Node* root,vector<int>&ans){
    //     if(root==NULL) return ;
    //     ans.push_back(root->val);
    //     for(auto it:root->children){
    //         help(it,ans);
    //     }
    // }
    
    // ITERATIVE
    
    
    vector<int> preorder(Node* root){
        vector<int>ans;
        stack<Node*>st;
        
        if(!root) return ans;
        
        st.push(root);
        while(!st.empty()){
            auto top=st.top();
            st.pop();
            ans.push_back(top->val);
            for(auto it=rbegin(top->children);it!=rend(top->children);it++)// loop from all the children from right to left and push them in stack
                st.push(*it);
            
        }
        return ans;
        
    }
    
};