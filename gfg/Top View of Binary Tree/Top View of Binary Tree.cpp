Time-O(N)
  Space-O(N) bcozz using queue and map
  
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int>ans;
        if(root==NULL) return ans;
        queue<pair<Node*,int>>q;
        map<int,int>mp;
        q.push({root,0});
        
        while(!q.empty()){
            
            auto it=q.front(); // pair bnata tu auto ne vo kaam khud kr dia tere lie  (pair<Node*,int> it ) ye bhi same hi h bt in short
            q.pop();
            Node* node=it.first;
            int line=it.second;
            if(mp.find(line)==mp.end()) mp[line]=node->data;  // isme find kr rhe h map mei ki agr phle khi line ki value same h to dont insert else insert
            
            if(node->left!=NULL) q.push({node->left,line-1});
            if(node->right!=NULL) q.push({node->right,line+1});
            
        }
        for(auto it:mp){
            ans.push_back(it.second);  // final ans mei push ke lie
        }
        return ans;
    }
