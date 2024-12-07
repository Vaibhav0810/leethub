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
    
    ListNode* rev(ListNode* prv,ListNode* curr,ListNode* next){
        if(next==NULL){
            curr->next=prv;
            return curr;
        }
        curr->next=prv;
        prv=curr;
        curr=next;
        next=next->next;
        return rev(prv,curr,next);
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        return rev(NULL,head,head->next);
        
    }
};