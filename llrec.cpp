#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
    //head = 2 4 8 3
    //smaller = 2 4 3
    //larger = 8
    //head = empty

    // struct Node {
    // int val;
    // Node *next;
    // }

    if (head == nullptr){
        smaller = NULL;
        larger = NULL;
    }else{
        llpivot(head->next, smaller, larger, pivot);

        if (head->val <= pivot){
            //add to front of smaller 
            head->next = smaller;
            smaller = head;
        }else{
            //add in front of larger 
            head->next = larger;
            larger = head;
        }

        head = nullptr;

    }
}
