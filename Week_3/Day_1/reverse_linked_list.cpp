#include <bits/stdc++.h>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*time - O(N)
space - O(1)*/
// N = number of nodes
ListNode* reverseList(ListNode* head) {
    ListNode* curr = head;
    ListNode* front;
    ListNode* prev = nullptr;
    while (curr != nullptr) {
        front = curr->next;   // save next node
        curr->next = prev;    // reverse link
        prev = curr;          // move prev forward
        curr = front;         // move curr forward
    }
    head = prev;
    return head;
}

int main() {
    // Example input: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Call the function
    ListNode* result = reverseList(head);

    // Print the result
    cout << "Reversed linked list: ";
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
