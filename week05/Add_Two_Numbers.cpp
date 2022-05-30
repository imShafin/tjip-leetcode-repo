/*
  TC: O(N) /// N = Number of Nodes
  MC: O(N) /// N =   ,,       ,,
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* newNode = res;
        int carry = 0;
        while(l1 || l2 || carry)
        {
            int firstNum = l1? l1->val : 0;
            int secondNum = l2? l2->val : 0;
            
            int num = firstNum + secondNum + carry;
            newNode->next = new ListNode(num % 10);
            newNode = newNode->next;
            carry = num / 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return res->next;
    }
};