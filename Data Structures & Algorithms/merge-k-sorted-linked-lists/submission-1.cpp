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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Iteration
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        
        while(true){
            int currMin = -1;
            for(int i =0 ; i<lists.size(); i++){
                if(!lists[i]) continue;
                if(currMin==-1 || lists[i]->val<lists[currMin]->val) {
                    currMin = i;
                }
            }
            if(currMin == -1) break;
            curr->next = lists[currMin];
            lists[currMin] = lists[currMin]->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};