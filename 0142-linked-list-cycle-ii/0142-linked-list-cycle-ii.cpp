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
    ListNode *detectCycle(ListNode *head) {
        
        // O(N)
//         set<ListNode*> st;
//         ListNode* slow=head;
//         while(slow){
            
//             if(st.find(slow)==st.end()){
//                 st.insert(slow);
//                 slow=slow->next;
//             }
//             else{
//                 return slow;
//             }
//         }
//         return NULL;
        
        //O(1)
        
        
        // ye iska logic ye h
        // fast double speed se chlkr vha phcha h jha cycle detect hui h
        // ab ye soch ki slow kuch tha hi ni aur fast 1 speed se chl rha tha
        // to vo half distance pr h ab jha pr h 
        // to ab slow ko aur fast ko 1 speed se jha vo h vhhha jaane ke lie same tym lgega
        // isilie ab jb bdd mei usse head se chlaenge to same vha vo ussi area pr match krenge jha se cycle start hogi
        
       ListNode* slow=head,*fast=head;
        
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        
        if(fast==NULL || fast->next==NULL) return NULL;
        
        while(head!=slow){
            head=head->next;
            slow=slow->next;
        }
        return head;
    }
};