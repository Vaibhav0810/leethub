/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=0;
        int lenB=0;
        
        if(headA==NULL || headB==NULL) return NULL;
        
        ListNode *tempA=headA;
        ListNode *tempB=headB;
        
        while(tempA!=NULL){
            tempA=tempA->next;
            lenA++;
        }
        while(tempB!=NULL){
            tempB=tempB->next;
            lenB++;
        }
        
        tempA=headA;
        tempB=headB;
        
        while(lenA>lenB){
            tempA=tempA->next;
            lenA--;
        }
        while(lenB>lenA){
            tempB=tempB->next;
            lenB--;
        }
        
        
        while(tempA!=NULL){
            if(tempA==tempB){
                return tempA;
            }
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return NULL;
        
        
    }
};