/*
TC: O(N) // N means number of Nodes.
MC: O(N) // N   ,,    ,,       ,,
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
      if (!head || !head -> next) return false;
      ListNode *oneStep = head;
      ListNode *twoStep = head -> next;
      while (oneStep != twoStep)
      {
        if (twoStep == NULL) return false;
        oneStep = oneStep -> next;
        twoStep = twoStep -> next;
        if(twoStep) twoStep = twoStep -> next;
        else return false;
      }
      return true;
    }
};
