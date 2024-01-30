struct TreeNode { 
  int data; 
  TreeNode *left; 
  TreeNode *right;
};

int maxsum = 0; 

void maxsum_r2l(struct TreeNode *t, int sum){
   if (!root) return; 
   
   if(t->left == NULL && t->right == NULL && sum + t->data > maxsum){
       maxsum = sum + t->data;
   }
   
   maxsum_r2l(t->left, sum + t->data);
   maxsum_r2l(t->right, sum + t->data);
}

