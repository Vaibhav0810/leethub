Better approach is, that will never fail at any constartint is using the reference for minNode, and maxNode. Actually this is the basic concept here to be used, first one is dependent on the constraint.
Following this approach, we came up to this solution:
```
class Solution {
public:
bool isValidBST(TreeNode* root) {
return fun(root, NULL, NULL);
}
bool fun(TreeNode* root, TreeNode* max, TreeNode* min){
if(root==NULL){
return true;
}
// Using the same above logic
//Just check if max or min-node is NULL, then follow it as true
if((min==NULL || root->val > min->val) && (max==NULL || root->val < max->val)){
return fun(root->left, root, min) && fun(root->right, max, root);
}
return false;
}
};
```