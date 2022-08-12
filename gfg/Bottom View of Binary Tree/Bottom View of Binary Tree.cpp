Time-
Space-O(N)

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        if(root==NULL) return ans;
        
        queue<pair<Node*,int>>q;
        map<int,int>mp;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node* temp=it.first;
            int index=it.second;
             mp[index]=temp->data; // ye isilie bcoz hme bottom view chahie and bottom vale bdd mei aayenge to sare enter kr doge to vo phle ke se replace kr dega usse
            
            if(temp->left) q.push({temp->left,index-1});
            if(temp->right) q.push({temp->right,index+1});
        }
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
