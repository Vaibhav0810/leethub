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
    bool isPalindrome(ListNode* head) {
    if (head == NULL) return true;

    ListNode* temp = head;
    int count = 0;

    // Count the number of nodes in the list
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    bool isOdd = (count % 2 != 0); // Check if the length is odd
    count /= 2; // Midpoint of the list

    // Reverse the first half of the list
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;

    for (int i = 0; i < count; i++) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // If the list has an odd length, skip the middle node
    if (isOdd) {
        curr = curr->next;
    }

    // Compare the reversed first half with the second half
    ListNode* firstHalf = prev;
    ListNode* secondHalf = curr;

    while (firstHalf != NULL && secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val) {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

};