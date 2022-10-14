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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head==NULL) return NULL;
        
        int count=0;
        
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        count=count/2;
        if(count==0) return NULL;
        temp=head;
        count=count-1;
        
        while(count--){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
        
    }
};