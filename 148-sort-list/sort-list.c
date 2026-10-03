/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */

// Helper function to merge two sorted linked lists
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    // Attach the remaining part of the list
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

// Helper function to find the middle of the list using slow/fast pointers
struct ListNode* getMiddle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct ListNode* sortList(struct ListNode* head) {
    // Base case: if the list is empty or has only one node
    if (!head || !head->next) {
        return head;
    }

    // 1. Split the list into two halves
    struct ListNode* mid = getMiddle(head);
    struct ListNode* leftHalf = head;
    struct ListNode* rightHalf = mid->next;
    mid->next = NULL; // Break the link to create two separate lists

    // 2. Recursively sort each half
    leftHalf = sortList(leftHalf);
    rightHalf = sortList(rightHalf);

    // 3. Merge the sorted halves
    return merge(leftHalf, rightHalf);
}