/* Find merge point of two linked list 
   A =  12->11->12->15->1->2->3->5->6->8->10->25
   B =              -1->0->2->3->5->6->7->30->31->32

   Algo: Alen = length(A);
         Blen = length(B);

         int diff = Alen - Blen;

         if(Blen > Alen){
            swap(A, B); 
            diff = Blen - Alen;
         }

         run a loop to walk A (the longer LL) by diff nodes.
         At this point both of the LL have same number of nodes, walk thru the nodes and compare each node. If two nodes of the LL are same we found the merge point.
*/

#include <iostream>

struct Node { 
  int data; 
  struct Node *next;
};

int listLength(struct Node *l){
  int count = 0;
  if(l){
    while(l){
      count++;
      l=l->next;
    }
  }
    return count;
}

sturct Node * findMergePoint(struct Node *A, struct Node *B){ 
  int Alen = listLength(A); 
  int Blen = listLength(B);

  if (Alen == 0 || Blen == 0) return NULL; // if one of the linked list is empty or both there is no merge point return NULL 
  int diff = Alen - Blen;

  if( diff < 0) {
    struct Node *temp = A;
    A = B; 
    B = temp;
    diff = -diff;
  }

  
  for(int i = 0; i < diff; i++){ // walk diff nodes in the longer linkedlist i.e. A
    A = A -> next;
  }

  while( A != NULL && B !=NULL ){
    if(A == B) return A;
    
    A = A->next;
    B = B->next;
  }

  return NULL; // no merge point found
}

  
  
