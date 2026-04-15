/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mpp;
        Node* temp = head;
        while(head){
            Node* temp = new Node(head->val);
            mpp[head] = temp;
            head = head->next;
        }
        for(auto it:mpp){
            if(it.first->next)
            it.second->next = mpp[it.first->next];
            else 
            it.second->next = NULL;
            if(it.first->random)
            it.second->random = mpp[it.first->random];
            else
            it.second->random = NULL;
        }
        return mpp[temp];
    }
};