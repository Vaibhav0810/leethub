/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*>q;
        q.push(root);
        while(q.size()>0){
            int n = q.size();
            int currSize = n;
            while(n--){
                auto top = q.front();
                q.pop();
                currSize--;
                if(currSize>0) {
                    auto second = q.front();
                    top->next= second;
                }
                else top->next=NULL;
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
        }
        return root;
    }
};