/*
TC: O(N)
MC: O(1)
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      if(!head || !head->next) return head;
      ListNode* curr = head->next;
      head->next = NULL;
      ListNode* linker; 
      while(curr)
      {
        linker = curr;
        curr = curr -> next;
        linker -> next = head;
        head = linker;
      }
      return head;
    }
};