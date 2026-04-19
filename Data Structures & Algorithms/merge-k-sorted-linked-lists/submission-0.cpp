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
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto node:lists){
            while(node){
                pq.push(node->val);
                node = node->next;
            }
        }
        while(!pq.empty()){
            int it = pq.top();
            ListNode* temp = new ListNode(it);
            tail->next = temp;
            tail = tail->next;
            pq.pop();
        }
        return dummy->next;
    }
};