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
    void deleteNode(ListNode* node) {
        
//         node->val=node->next->val;
//         node->next=node->next->next;
        
        // auto next=node->next;
        // *node=*next;
        // delete next;
        // ye upr ko aise bhi likh skte h isme bs kuch ni h node del kr rhe h
        ListNode* temp=node->next;
        node->val=temp->val;
        node->next=temp->next;
        delete(temp);
        
    }
};