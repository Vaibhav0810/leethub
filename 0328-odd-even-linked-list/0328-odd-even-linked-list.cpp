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
    // ListNode* oddEvenList(ListNode* head) {
    //     ListNode* odd=head;
    //     ListNode* temp2=head->next;
    //     //ListNode* temp=odd;
    //     while(odd->next){
    //         odd->next=odd->next->next;
    //         odd=odd->next;
    //     }
    //     //odd->next=NULL;
    //     ListNode* even=temp2;
    //     //head=head->next;
    //     while(even->next){
    //         even->next=even->next->next;
    //         even=even->next;
    //     }
    //     //even->next=NULL;
    //     //return temp2;
    //     odd->next=temp2;
    //     return head;
    // }
    
      ListNode* oddEvenList(ListNode* head){
          if(!head) return head;
          ListNode* odd=head;
          ListNode* even=head->next;
          ListNode* even_head=head->next;
          
          while(even && even->next){
              odd->next=odd->next->next;
              even->next=even->next->next;
              odd=odd->next;
              even=even->next;
          }
          odd->next=even_head;
          return head;
      }
    
};