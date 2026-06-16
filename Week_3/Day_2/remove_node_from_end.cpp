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
int lengthLL(ListNode* head) {
    int count = 0;
    ListNode* curr = head;
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int len = lengthLL(head);
    int pos = len - n;
    ListNode* curr = head;

    // remove head
    if (pos == 0) {
        return head->next;
    }

    for (int i = 0; i < pos - 1; i++) {
        curr = curr->next;
    }

    // remove node
    curr->next = curr->next->next;
    return head;
}

int main() {
    // Example input: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Call the function (remove 2nd node from end → remove 4)
    head = removeNthFromEnd(head, 2);

    // Print the result
    cout << "List after removal: ";
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
