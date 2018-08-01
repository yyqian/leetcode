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
    bool hasCycle(ListNode *head) {
        ListNode* walker = head;
        ListNode* runner = head;
        do {
            if (!runner || !(runner->next)) return false;
            walker = walker->next;
            runner = runner->next->next;
        } while (walker != runner);
        return true;
    }
};