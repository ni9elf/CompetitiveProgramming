/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/
#include <unordered_map>

bool has_cycle(Node* head) {
    if (head == NULL)    
        return false;
    else {
        unordered_map<Node*, int> addresses;
        addresses[head] = 0;
        Node *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
            if (addresses.find(ptr) != addresses.end())
                return true;            
            else
                addresses[ptr] = 0;            
        }
        return false;
    }
}
