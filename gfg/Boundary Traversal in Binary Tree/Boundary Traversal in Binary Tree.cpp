Time-O(N) and Space-O(N)
  we dont count the data structure in which we return ans so dont count vector<int> ans
class Solution {
public:
    
    void leftnodes(Node* root,vector<int>& ans){
        Node* temp=root->left;
        while(temp){
            if(!isLeaf(temp)){
                ans.push_back(temp->data);
                
            }
            if(temp->left) temp=temp->left;
            else  temp=temp->right;
        }
    }
    
    void rightnodes(Node* root,vector<int>&ans){
        Node*temp=root->right;
        vector<int>v;
        while(temp){
            if(!isLeaf(temp)) v.push_back(temp->data);
            if(temp->right) temp=temp->right;
            else temp=temp->left;
        }
        for(int i=v.size()-1;i>=0;--i){ // ye rev kr rhe h bcoz anticlockwise mei chahie ans mei to
            ans.push_back(v[i]);
        }
    }
    
    void leafnodes(Node* root,vector<int>&ans){
        Node* temp=root;
        if(isLeaf(temp)) {
            ans.push_back(temp->data);
            return;
            
        }
        if(temp->left) leafnodes(temp->left,ans);
        if(temp->right) leafnodes(temp->right,ans);
            
    }
    
    bool isLeaf(Node* root){
        if(root->left==NULL && root->right==NULL) return true;
        else return false;
    }

    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(root==NULL) return ans;
        if(!isLeaf(root)) ans.push_back(root->data);
        leftnodes(root,ans);
        leafnodes(root,ans);
        rightnodes(root,ans);
        return ans;
    }
};

  SUMMARY
  isme phle hmne root node daala ans mei then leftnodes function call kr dia and then we push left nodes in ans
  after that we push all leaf nodes 
  after that we push all right nodes

