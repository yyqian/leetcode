/*
Given a linked list, remove the n-th node from the end of list and return its
head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* front = &dummy;
    ListNode* target = &dummy;
    for (int i = 0; i < n + 1; ++i) {
      front = front->next;
    }
    while (front != nullptr) {
      front = front->next;
      target = target->next;
    }
    ListNode* to_remove = target->next;
    target->next = to_remove->next;
    to_remove->next = nullptr;
    return dummy.next;
  }
};
// 哨兵节点 + runner