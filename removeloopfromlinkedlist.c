/* Detect and remove loop from a linked list */

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int value;
    struct ListNode* next;
};

// Function to remove a cycle in a linked list
void removeCycle(struct ListNode* head, struct ListNode* meetingPoint) {
    struct ListNode *ptr1 = head;
    struct ListNode *ptr2 = meetingPoint;
    
    while(ptr1->next != ptr2->next){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    /* this is where the loop starts. Set the node's next to NULL to remove the
       loop */
    
    ptr2->next = NULL;
    
}

// Function to detect a loop in a linked list and remove it
int detectAndRemoveCycle(struct ListNode* head) {
    if((head == NULL) || (head->next == NULL) ) return 0;
    
    struct ListNode *fast = head;
    struct ListNode *slow = head;
                                                              //fast
                                                              //      slow
                                                              // V.   V
    while(fast !=NULL && fast->next != NULL){//.   fast -> 1 -> 2 -> 3 -> 4
        fast = fast -> next ->next;
        slow = slow->next;

        if (slow == fast){
            removeCycle(head, slow);
            return 1;
        }
    }
    
    return 0;
}



// Function to create a new linked list node
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list with a cycle (for testing)
struct ListNode* createCyclicList() {
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = head->next; // Create a cycle

    return head;
}

// Function to free the memory allocated for a linked list
void freeLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    // Example usage to test the detectAndRemoveCycle function

    // Create a linked list with a cycle (for testing)
    struct ListNode* listWithCycle = createCyclicList();

    // Detect and remove the cycle in the list with a cycle
    if (detectAndRemoveCycle(listWithCycle)) {
        printf("Cycle detected and removed.\n");
    } else {
        printf("No cycle detected.\n");
    }

    // Free the memory allocated for the list with a cycle
    //freeLinkedList(listWithCycle);

    return 0;
}

