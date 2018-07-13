/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) {
      ListNode left_head(0);
      ListNode* left_end = &left_head;
      ListNode right_head(0);
      ListNode* right_end = &right_head;
      while (head != nullptr) {
        if (head->val < x) {
          left_end->next = head;
          left_end = left_end->next;
        } else {
          right_end->next = head;
          right_end = right_end->next;
        }
        head = head->next;
      }
      left_end->next = right_head.next;
      right_end->next = nullptr;
      return left_head.next;
    }
};