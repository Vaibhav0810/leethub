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
//     vector<ListNode*>v;
//     Solution(ListNode* head) {
//         while(head){
//             v.push_back(head);
//             head=head->next;
//         }
//     }
    
//     int getRandom() {
//         int i=rand()%v.size();
//         return v[i]->val;
//     }
    
    // without extra space by calculating size
    int n=0;
    ListNode* temp=NULL;
        Solution(ListNode* head){
            temp=head;
            while(head){
                n++;
                head=head->next;
            }
        }
    
        int getRandom(){
            int i=rand()%n;
            ListNode* p=temp;
            while(i>0){
                p=p->next;
                i--;
            }
            return p->val;
        }
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */