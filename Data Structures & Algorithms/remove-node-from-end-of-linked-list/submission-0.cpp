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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;
        while(temp){
            size++;
            temp = temp->next;
        }
        if(size==1 && n==1) return NULL;
        int rm = size-n;
        temp = head;
        ListNode* prev = NULL;
        if(size==n) return head->next;
        while(rm>1){
            prev = temp;
            temp = temp->next;
            rm--;
        }
        if(temp->next)
            temp->next = temp->next->next;
        else{
            //removing last node
            prev->next = NULL;
        }
        return head;
    }
};