/* Binary Tree TO doubly linkedlist */

TreeNode *head = NULL, *prev = NULL;

void BTtoDLL(TreeNode *root){
  if(!root) return;

  BTtoDLL(root->left); 

  if(prev == NULL) head = root;
  else {
    root->left = prev;
    prev->right = root
  }
  prev = root;

  BTtoDLL(root->right); 
}
