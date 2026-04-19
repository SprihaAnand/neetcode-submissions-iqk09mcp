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
    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2){
        ListNode* ans = new ListNode(-1);
        ListNode* tail = ans;
        while(l1 || l2){
            int one = l1?l1->val:INT_MAX;
            int two = l2?l2->val:INT_MAX;
            if(one>two) {
                tail->next = l2;
                l2=l2->next;
                tail = tail->next;
            } else{
                tail->next = l1;
                l1=l1->next;
                tail = tail->next;    
            }
        }
        return ans = ans->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
        for(int i = 1; i<lists.size(); i++){
            lists[i] = mergeTwoSortedLists(lists[i-1], lists[i]);
        }
        int n = lists.size();
        return lists[n-1];
    }
};