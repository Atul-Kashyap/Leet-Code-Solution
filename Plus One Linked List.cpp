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

// Approach 1: Sentinel Head + Textbook Addition.
// Time Complexity : O(N)
// Space Complexity : O(1)
    
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode* sentinel = new ListNode(0);
        sentinel -> next = head;
        ListNode* notNine = sentinel;
        while(head != NULL){
            if(head -> val != 9)
                notNine = head;
            head = head -> next;
        }
        notNine->val += 1;
        notNine = notNine->next;
         while(notNine != NULL){
             notNine->val = 0;
             notNine = notNine -> next;
         }
        return sentinel->val != 0 ? sentinel : sentinel->next;
    }
};
