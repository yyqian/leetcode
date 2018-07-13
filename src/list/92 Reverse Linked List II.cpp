/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
      ListNode dummy(0);
      ListNode dummy2(0);
      dummy.next = head;
      ListNode* left_end;
      ListNode* mid_end;
      ListNode* current = &dummy;
      int idx = 0;
      while (idx <= n) {
        if (idx == m - 1) {
          left_end = current;
          mid_end = current->next;
          current = current->next;
        } else if (idx >= m) {
          ListNode* tmp = dummy2.next;
          dummy2.next = current;
          current = current->next;
          dummy2.next->next = tmp;
        } else {
          current = current->next;
        }
        ++idx;
      }
      left_end->next = dummy2.next;
      mid_end->next = current;
      return dummy.next;
    }
};