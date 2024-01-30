int maxlevel = 0; 

void rightviewofBT(struct TreeNode *t, int level){

  if (!root) return; 

  if (level >= maxlevel){
    cout << t->data;
    maxlevel ++;
  }


  rightviewofBT(t->right, level + 1);
  rightviewofBT(t->left, level + 1);

}
  
