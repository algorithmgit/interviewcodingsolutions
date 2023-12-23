/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if( head == NULL) return nullptr;

        unordered_map<Node *, Node*> um;
        
        Node *cur = head;
        while(cur){
            um[cur] = new Node(cur->val);
            cur = cur->next;
        }
      
        cur = head;
        while(cur){
            um[cur]->next = um[cur->next];
            um[cur]->random = um[cur->random];
            cur = cur->next;
        }        
        return um[head];        
    }
};

/* Output:
Case 1:
Input
[[7,null],[13,0],[11,4],[10,2],[1,0]]
Output
[[7,null],[13,0],[11,4],[10,2],[1,0]]
Expected
[[7,null],[13,0],[11,4],[10,2],[1,0]]

Case 2:
Input
[[1,1],[2,1]]
Output
[[1,1],[2,1]]
Expected
[[1,1],[2,1]]

Case 3:
Input
[[3,null],[3,0],[3,null]]
Output
[[3,null],[3,0],[3,null]]
Expected
[[3,null],[3,0],[3,null]]
*/

