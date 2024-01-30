int sumRootToLeaf = 0; 

void sumRootToLeaf(struct TreeNode *t, int i){
  if (!root) return;

  if (t->left == NULL && t->right == NULL){
    sumRootToLeaf += (i * 10 + t->data); 
  }

  sumRootToLeaf(t->left, (i * 10 + t->data));
  sumRootToLeaf(t->right, (i * 10 + t->data));
}

int main(){
  sumRootToLeaf(root, 0);

  return 0;
}
