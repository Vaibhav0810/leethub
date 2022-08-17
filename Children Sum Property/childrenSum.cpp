
// isme neeche jaate jaate dekhenge agr root->left ki value root se choti h to root->left pr root ki value de denge and aise hi same neeche neeche tk ab neeche se up
// aate hue right n left dono ki  value ko add krte jaayenge to firr shi tree bnn jayega 
// bt agr root->left ya root.right ki value root ki value se bdi h to kuch ni krenge just neeche jaatyenge aur firr neeche see upr aate hue left right add krte jaayenge
// and final ans aajayega
//eg
// link in description
            40
          /    \
        10     20
       /  \   /  \
      2   5  30  40
              
            ||
              
            150
          /     \
         80      70
         /\      /\
        40 40   30 40
              
 void reorder(node * root) {
  if (root == NULL) return;
  int child = 0;
  if (root -> left) {
    child += root -> left -> data;
  }
  if (root -> right) {
    child += root -> right -> data;
  }

  if (child < root -> data) {
    if (root -> left) root -> left -> data = root -> data;
    else if (root -> right) root -> right -> data = root -> data;
  }

  reorder(root -> left);
  reorder(root -> right);

  int tot = 0;
  if (root -> left) tot += root -> left -> data;
  if (root -> right) tot += root -> right -> data;
  if (root -> left || root -> right) root -> data = tot;
}
void changeTree(node * root) {
  reorder(root);
}
