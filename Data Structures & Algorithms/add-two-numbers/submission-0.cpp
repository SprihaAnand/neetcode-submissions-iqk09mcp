/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* save = dummy;
        while(l1 && l2) {
            int sum = l1->val + l2->val+carry;
            int sumtemp = sum%10;
            ListNode* temp = new ListNode(sumtemp);
            dummy->next = temp;
            dummy = dummy->next;
            carry = sum/10;
            l1=l1->next;
            l2 = l2->next;
        }
        while(l2){
            int sum = carry+l2->val;
            int sumtemp = sum%10;
            ListNode* temp = new ListNode(sumtemp);
            dummy->next = temp;
            dummy = dummy->next;
            carry = sum/10;
            l2 = l2->next;
        }
        while(l1){
            int sum = carry+l1->val;
            int sumtemp = sum%10;
            ListNode* temp = new ListNode(sumtemp);
            dummy->next = temp;
            dummy = dummy->next;
            carry = sum/10;
            l1 = l1->next;
        }
        if(carry){
            ListNode* temp = new ListNode(carry);
            dummy->next = temp;
            dummy = dummy->next;
        }
        return save->next;
    }
};