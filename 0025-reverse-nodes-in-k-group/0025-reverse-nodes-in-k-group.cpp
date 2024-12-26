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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1) return head;
        ListNode* dummyNode = new ListNode (0);
        dummyNode->next=head;
        ListNode* prv= dummyNode;
        ListNode* curr= dummyNode;
        ListNode* next = dummyNode;
        int count=0;
        while(curr->next!=NULL){
            count++;
            curr=curr->next;
        }
        
        // prv=dummyNode;
        
        while(count>=k){
            curr=prv->next;
            next=curr->next;
            for(int i=1;i<k;i++){
                curr->next=next->next;
                next->next=prv->next;
                prv->next=next;
                next=curr->next;
            }
            prv=curr;
            count-=k;
        }
        return dummyNode->next;
        
    }
};