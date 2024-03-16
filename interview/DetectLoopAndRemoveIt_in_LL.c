#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to detect and remove loop in a linked list
void detectAndRemoveLoop(struct Node* head) {
    if (head == NULL || head->next == NULL) return; // No loop or single node

    struct Node *slowPtr = head, *fastPtr = head;

    // Move slowPtr one step and fastPtr two steps at a time until they meet
    while (fastPtr != NULL && fastPtr->next != NULL) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        // If slowPtr and fastPtr meet, break the loop
        if (slowPtr == fastPtr) break;
    }

    // If loop exists, start slowPtr from head and move both pointers one step at a time until they meet
    if (slowPtr == fastPtr) {
        slowPtr = head;
        while (slowPtr->next != fastPtr->next) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
        // Fast pointer now points to the last node of the loop. Remove the loop by pointing its next to NULL.
        fastPtr->next = NULL;
    }
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to create a new node
struct Node* newNode(int key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = key;
    temp->next = NULL;
    return temp;
}

int main() {
    // Create a linked list with a loop
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    // Create a loop for testing
    head->next->next->next->next->next = head->next->next;

    // Detect and remove loop
    detectAndRemoveLoop(head);

    printf("Linked list after removing loop: \n");
    printList(head);

    return 0;
}
/* Output 

Linked list after removing loop: 
1 2 3 4 5 

*/
