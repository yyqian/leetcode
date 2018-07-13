/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode dummy(0);
      dummy.next = head;
      ListNode* current = &dummy;
      while(current != nullptr && current->next != nullptr && current->next->next != nullptr) {
        if (current->next->val != current->next->next->val) {
          current = current->next;
        } else {
          ListNode* tmp = current->next->next->next;
          while (tmp != nullptr && tmp->val == current->next->val) {
            tmp = tmp->next;
          }
          current->next = tmp;
        }
      }
      return dummy.next;
    }
};