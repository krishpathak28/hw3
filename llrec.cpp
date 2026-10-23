#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    // Phase 1: The Base Case
    if (head == NULL) {
        smaller = NULL;
        larger = NULL;
        return;
    }

    // Phase 2: Isolate the Current Node
    Node* nextNode = head->next;

    // Phase 3: The Recursive Step (Distribution)
    if (head->val <= pivot) {
        smaller = head; 
        llpivot(nextNode, smaller->next, larger, pivot);
    } else {
        larger = head;
        llpivot(nextNode, smaller, larger->next, pivot);
    }

    // Phase 4: Cleanup
    head = NULL;
}