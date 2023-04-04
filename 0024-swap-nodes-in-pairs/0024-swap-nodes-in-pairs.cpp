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
//     ListNode* swapPairs(ListNode* head) {
        
//         if(!head || !head->next) return head;
        
//         ListNode* dummy=new ListNode();
//         ListNode* prv=dummy,*curr=head;
//         while(curr && curr->next){
//             prv->next=curr->next;
//             curr->next=prv->next->next;
//             prv->next->next=curr;
//             prv=curr;
//             curr=curr->next;
//         }
//         return dummy->next;
        
//     }
    
    // recursion
    
    void recur(ListNode* prv,ListNode* curr){
        if(!curr || !curr->next) return ;
        
        prv->next=curr->next;
        curr->next=prv->next->next;
        prv->next->next=curr;
        
         recur(curr,curr->next);
        
    }
    
    ListNode* swapPairs(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* dummy=new ListNode();
        recur(dummy,head);
        return dummy->next;
    }
};