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
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    // Find middle of the list
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    ListNode *prev = nullptr, *curr = slow;
    while (curr) {
        ListNode *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }

    // Compare first and second half
    ListNode *first = head, *second = prev;
    while (second) {
        if (first->val != second->val) return false;
        first = first->next;
        second = second->next;
    }

    return true;
}

int main() {
    // Example input: 1 -> 2 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    // Call the function
    bool result = isPalindrome(head);

    // Print the result
    cout << (result ? "List is a palindrome" : "List is not a palindrome");
    return 0;
}
