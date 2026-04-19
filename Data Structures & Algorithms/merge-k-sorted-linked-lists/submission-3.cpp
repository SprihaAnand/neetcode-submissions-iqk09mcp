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
    ListNode* divide(vector<ListNode*> lists, int l, int r){
        if(l>r) return NULL;
        if(l==r) return lists[l];
        int mid = (r-l)/2+l;
        ListNode* right = divide(lists, l, mid);
        ListNode* left = divide(lists, mid+1, r);
        return conquer(right, left);
    }
    ListNode* conquer(ListNode* l1, ListNode* l2){
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;
        while(l1 || l2){
            int one = l1?l1->val:INT_MAX;
            int two = l2?l2->val:INT_MAX;
            if(one<two){
                tail->next = l1;
                l1 = l1->next;
                tail = tail->next;
            } else{
                tail->next = l2;
                l2 = l2->next;
                tail = tail->next;
            }
        }
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        int n = lists.size();
        return divide(lists, 0, n-1);
    }
};