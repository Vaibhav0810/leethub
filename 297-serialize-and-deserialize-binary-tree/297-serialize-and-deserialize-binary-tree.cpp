/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//kya hi ho rha h pta ni
// mzk chd pdh le

// ismme ye krna h ki phle ik string mei tumhe pura tree daalna h firr uss string se vps tree bnana h

//TC-O(N) SC-O(N)

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(!root) return "";
        
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            
            if(temp==NULL) s.append("#,"); // agr null h to # daal denge jiss se pta chl jaye null h
            else s.append(to_string(temp->val)+','); // ni to simple sari value
            
            if(temp!=NULL){ // ye iislie bcoz agr ye check ni krenge to null ki jgh # push hota rhega endless
                q.push(temp->left);
                q.push(temp->right);
            }
            
        }
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.size()==0) return NULL;
        
        stringstream s(data);  // kind of input ko words mei break kr deta h
        string str;
        getline(s,str,',');  // iska mtlb h jaise ye string h 1,2,3,#,.... to ye line tumhe , se phle ki cheeze de degi(like 1   2  aise)
        
        // baaki firr isme ye kia h dekha h ki string mei agli value kaunsi h agr # h to null lga do ni to vo number lga do
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            getline(s,str,',');
            
            if(str=="#"){
                temp->left=NULL;
            }
            else{
                TreeNode* leftnode=new TreeNode(stoi(str)); // ye isilie bcoz number lgana h aur string mei char bnakr pass kia tha
                temp->left=leftnode;
                q.push(leftnode);
            }
            
            getline(s,str,',');
            
            if(str=="#") temp->right=NULL;
            else{
                TreeNode* rightnode=new TreeNode(stoi(str));
                temp->right=rightnode;
                q.push(rightnode);
            }
            
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));