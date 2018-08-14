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

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
      if (!head) return head;
      RandomListNode *l1, *l2;
      l1 = head;
      while (l1) {
        l2 = new RandomListNode(l1->label);
        l2->next = l1->next;
        l1->next = l2;
        l1 = l2->next;
      }
      l1 = head;
      while (l1) {
        if (l1->random) {
          l1->next->random = l1->random->next;
        }
        l1 = l1->next->next;
      }
      l1 = head;
      l2 = head->next;
      while (l1) {
        RandomListNode *tmp = l1->next->next;
        if (tmp) l1->next->next = tmp->next;
        l1->next = tmp;
        l1 = tmp;
      }
      return l2;
    }
};