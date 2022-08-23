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
    // we reverse the linked list and then slow is now pointing to half+1 and then we check if they equal or not
    // detail register mei h
    
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL || head->next==NULL) return 1;
        ListNode* temp=head;
        ListNode* slow=temp;
        ListNode* fast=temp;
        
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        slow->next=reverse(slow->next);
            slow=slow->next;
            while(slow){
                if(head->val!=slow->val)return false;
                head=head->next;
                slow=slow->next;
            }
        return true;
        
    }
    
    ListNode* reverse(ListNode* slow){
        ListNode* prv=NULL;
        ListNode* fwd=NULL;
        
        while(slow){
            fwd=slow->next;
            slow->next=prv;
            prv=slow;
            slow=fwd;
            
        }
        
        return prv;
    }
    
};