/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
      unordered_map<RandomListNode*, RandomListNode*> mapping;
      RandomListNode dummy(0);
      RandomListNode *current = &dummy;
      RandomListNode *raw_head = head;
      while (head) {
        current->next = new RandomListNode(head->label);
        mapping.insert({head, current->next});
        current = current->next;
        head = head->next;
      }
      head = raw_head;
      while (head) {
        if (head->random) mapping.find(head)->second->random = mapping.find(head->random)->second;
        head = head->next;
      }
      return dummy.next;
    }
};