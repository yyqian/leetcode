/*
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
  ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode* current = head;
    int len = 0;
    while (current) {
      ++len;
      current = current->next;
    }
    ListNode* right = split(head, len / 2);
    ListNode* left = sortList(head);
    right = sortList(right);
    ListNode dummy(0);
    current = &dummy;
    while (left && right) {
      if (left->val < right->val) {
        current->next = left;
        left = left->next;
      } else {
        current->next = right;
        right = right->next;
      }
      current = current->next;
    }
    if (left) {
      current->next = left;
    } else {
      current->next = right;
    }
    return dummy.next;
  }

  ListNode* split(ListNode* head, int p) {
    int cnt = 1;
    while (cnt < p) {
      head = head->next;
      ++cnt;
    }
    ListNode* tmp = head->next;
    head->next = nullptr;
    return tmp;
  }
};