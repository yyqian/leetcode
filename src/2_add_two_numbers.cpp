struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class SolutionRecur {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    return recurAdd(l1, l2, 0);
  }

 private:
  ListNode* recurAdd(ListNode* l1, ListNode* l2, int carry) {
    if (l1 == nullptr && l2 == nullptr && carry != 0) {
      ListNode* last = new ListNode(carry);
      return last;
    }
    if (l1 == nullptr && l2 == nullptr && carry == 0) {
      return nullptr;
    }
    int l1_val = nullptr == l1 ? 0 : l1->val;
    int l2_val = nullptr == l2 ? 0 : l2->val;
    ListNode* l1_next = nullptr == l1 ? nullptr : l1->next;
    ListNode* l2_next = nullptr == l2 ? nullptr : l2->next;
    int sum = l1_val + l2_val + carry;
    int remainder = sum % 10;
    int dividend = sum / 10;
    ListNode* current = new ListNode(remainder);
    current->next = recurAdd(l1_next, l2_next, dividend);
    return current;
  }
};

class SolutionIter {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = nullptr;
    ListNode* prev = nullptr;
    int carry = 0;
    while(l1 || l2) {
      int v1 = l1 ? l1->val : 0;
      int v2 = l2 ? l2->val : 0;
      int sum = v1 + v2 + carry;
      carry = sum / 10;
      ListNode* current = new ListNode(sum % 10);
      if (!head) {
        head = current;
      }
      if (prev) {
        prev->next = current;
      }
      prev = current;
      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
    }
    if (carry != 0) {
      prev->next = new ListNode(carry);
    }
    return head;
  }
};