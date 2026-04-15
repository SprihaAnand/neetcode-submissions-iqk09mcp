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
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode *curr = head, *prev = NULL, *next = curr->next;
        while(curr){
            curr->next = prev;
            prev = curr;
            curr = next;
            if(curr) next = curr->next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        mid = reverse(mid);
        // 1 2 3 4 5
        // 1 2 3 4 
        ListNode* t1 = head, *t2 = mid;
        while(t2){
            ListNode* m = t1->next;
            ListNode* n = t2->next;
            t1->next = t2;
            t2->next = m;
            t1 = m;
            t2 = n;
        }
        // return head;
    }
};
