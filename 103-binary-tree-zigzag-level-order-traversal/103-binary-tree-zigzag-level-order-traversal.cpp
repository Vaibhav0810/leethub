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

/*
    isme zig zag jaana h phle l to r print then r to l print 
    so we will make a count var and if its 1 me go r to l ans if its 2 we go l to r
    and we store according to that in queue
    rest in same as bfs
    ye logic iss code ke lie tha bt after some test case i realised it wont work like her
    [1,2,3,4,null,null,5]
    it will print [1][3,2][5,4] but correct is[4,5]
    so new logic down below
*/

// if(count==1){
//                     v.push_back(q.front()->val);
//                     TreeNode* temp=q.front();
//                     q.pop();
//                     if(temp->right!=NULL){
//                         q.push(temp->right);
//                     }
//                     if(temp->left!=NULL){
//                         q.push(temp->left);
//                     }
                    
//                 }
//                 else{
//                     v.push_back(q.front()->val);
//                     TreeNode* temp=q.front();
//                     q.pop();
//                      if(temp->left!=NULL){
//                         q.push(temp->left);
//                     }
//                     if(temp->right!=NULL){
//                         q.push(temp->right);
//                     }
                    
//                 }
//             }
//             if(count==1) count++;
//             else count--;
//             ans.push_back(v);

// ye jo upr approach sochi thi uska correct code

class Solution {
public:
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        bool flag=true; // true means l to r and vice versa
        
        if(root==NULL) return ans;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>v(n);
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                
                int index=flag? i:n-1-i;
                v[index]=temp->val;
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
            flag=!flag;// for changing into true or false (in short agr true hoga to false n then ulta)
            ans.push_back(v);
        }
        return ans;
        
    }
};
            
/*
    we will maintain a count var if its 2 we rev our vector v and then push in ans 
    else we will push direct
*/

/* class Solution {
public:
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    int count=0;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root==NULL) return ans;
        q.push(root);
        count++;
        while(!q.empty()){
            vector<int>v;
            int n=q.size();
            for(int i=0;i<n;i++){
                
                    v.push_back(q.front()->val);
                    TreeNode* temp=q.front();
                    q.pop();
                     if(temp->left!=NULL){
                        q.push(temp->left);
                    }
                    if(temp->right!=NULL){
                        q.push(temp->right);
                    }
                    
                }
            
            if(count==2){
                reverse(v.begin(),v.end());
                count--;
                ans.push_back(v);
            }
            else{
                count++;
                    ans.push_back(v);
            }
            
        }
        return ans;
        
    }
};
*/