/*
Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
Note:

Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be
changed.
*/

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    ListNode dummy(0);
    ListNode* last = &dummy;
    while (true) {
      if (head == nullptr) {
        break;
      } else if (head->next == nullptr) {
        last->next = head;
        break;
      }
      ListNode* tmp = head->next->next;
      last->next = head->next;
      last->next->next = head;
      last->next->next->next = nullptr;
      last = last->next->next;
      head = tmp;
    }
    return dummy.next;
  }
};