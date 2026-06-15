#include <bits/stdc++.h>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*time - O(N)
space - O(1)*/
// N = number of nodes
bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    // Example input: create a cycle
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // create cycle: last node points to second node
    head->next->next->next->next = head->next;

    // Call the function
    bool result = hasCycle(head);

    // Print the result
    cout << (result ? "Cycle detected" : "No cycle detected");
    return 0;
}
