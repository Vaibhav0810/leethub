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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL) return NULL;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* newList=new ListNode(-1);
        ListNode* temp=newList;
        int store=0;
        int sum=0;
        while(l1!=NULL && l2!=NULL){
            sum = l1->val+l2->val;
            if(store>0) sum+=store;
            store=0;
            if(sum>9){
                store=sum/10;
                sum=sum%10;
            }
            temp->next=new ListNode(sum);
            temp=temp->next;
            l1=l1->next;
            l2=l2->next;
            sum=0;
        }
        while(l1!=NULL){
            sum=l1->val+store;
            store=0;
            if(sum>9){
                store=sum/10;
                sum=sum%10;
            }
            temp->next=new ListNode(sum);
            temp=temp->next;
            l1=l1->next;
            sum=0;
        }
        while(l2!=NULL){
             sum=l2->val+store;
            store=0;
            if(sum>9){
                store=sum/10;
                sum=sum%10;
            }
            temp->next=new ListNode(sum);
            temp=temp->next;
            l2=l2->next;
            sum=0;
        }
        sum+=store;
        if(sum>0) temp->next=new ListNode(sum);
        temp=temp->next;
        return newList->next;
    }
};