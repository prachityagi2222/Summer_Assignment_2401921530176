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
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    // Example input: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Call the function
    ListNode* result = middleNode(head);

    // Print the result
    cout << "Middle node value: " << result->val << "\n";
    cout << "Remaining list from middle: ";
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
