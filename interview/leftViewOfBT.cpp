
int maxlevel = 0; 

void leftviewofBT(struct TreeNode *t, int level){

  if (!root) return; 

  if (level >= maxlevel){
    cout << t->data;
    maxlevel ++;
  }

  leftviewofBT(t->left, level + 1);
  leftviewofBT(t->right, level + 1);

}
  
