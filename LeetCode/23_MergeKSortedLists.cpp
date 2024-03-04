/* 23. Merge k Sorted Lists 
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
*/ 


#include <iostream>
#include <queue>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Comparator function for priority queue
struct CompareNodes {
    bool operator()(const ListNode* l1, const ListNode* l2) const {
        return l1->val > l2->val; // Min-heap based on node values
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNodes> pq;

        // Push the first nodes of all lists into the priority queue
        for (auto list : lists) {
            if (list)
                pq.push(list);
        }

        // Dummy node to ease the manipulation of the merged list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        // Iterate until the priority queue is empty
        while (!pq.empty()) {
            // Pop the node with the minimum value
            ListNode* node = pq.top();
            pq.pop();

            // Append this node to the merged list
            tail->next = node;
            tail = tail->next;

            // Move to the next node in the list of the popped node
            if (node->next)
                pq.push(node->next);
        }

        return dummy->next;
    }
};

// Function to print the merged list
void printList(ListNode* node) {
    while (node) {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Solution sol;

    // Example usage
    vector<ListNode*> lists;
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);

    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);

    ListNode* mergedList = sol.mergeKLists(lists);
    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
/* Output : 
Merged List: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6 -> NULL 
*/ 
