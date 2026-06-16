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

/*time - O(N + M)
space - O(1)*/
// N = length of list1, M = length of list2
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    ListNode* head;
    if (list1->val <= list2->val) {
        head = list1;
        list1 = list1->next;
    } else {
        head = list2;
        list2 = list2->next;
    }

    ListNode* curr = head;
    while (list1 && list2) {
        if (list1->val <= list2->val) {
            curr->next = list1;
            list1 = list1->next;
        } else {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }

    if (list1) curr->next = list1;
    else curr->next = list2;

    return head;
}

int main() {
    // Example input: list1 = [1,2,4], list2 = [1,3,4]
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    // Call the function
    ListNode* result = mergeTwoLists(list1, list2);

    // Print the result
    cout << "Merged sorted list: ";
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
