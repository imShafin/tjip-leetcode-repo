/*
TC: O(N) N means number of nodes
MC: O(2 * N)
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* forwardStep = head;
      ListNode* backStep = head;
      while (n--)
      {
        forwardStep = forwardStep -> next;
      }
      if (!forwardStep) return head -> next;
      while(forwardStep -> next)
      {
        backStep = backStep -> next;
        forwardStep = forwardStep -> next;
      }
      backStep -> next = backStep -> next -> next;
      return head;
    }
};
