#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data; 
  struct Node *next; 
};

struct Node *reverse (struct Node *n){
    struct Node *prev = NULL; 
    struct Node *next = NULL;
    struct Node *curr = n;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    n = prev;
    
    return n;
}

void printNode(struct Node *n){

  while(n){
    printf("%d ", n->data);
    n = n->next;
  }
  printf("\n");
  
  return;
}

/* Add a node in the beginning */
struct Node * addNodeToList(struct Node *h, int val){

  struct Node *temp = (struct Node *) malloc (sizeof(struct Node));

  temp -> data = val;
  temp -> next = h;
  h = temp;

  return h;
}


int main(){
  struct Node *head = NULL; 

  head = addNodeToList(head, 3); 
  head = addNodeToList(head, 2); 
  head = addNodeToList(head, 1);

  printNode(head); 
  head = reverse(head);
  printNode(head); 

}

