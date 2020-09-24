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

// Approach 1: Sentinel Node
// Time Complexity : O(N)
// Space Complexity : O(1)
    
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* sentinel = new ListNode(0);
        sentinel -> next = head;
        ListNode *prev = sentinel, *curr = head, *todelete = NULL;
        while(curr != NULL){
            
            if(curr -> val == val){
                prev -> next = curr -> next;
                todelete = curr;
            } 
            else 
                prev = curr;
            
            curr = curr -> next;
            
            if(todelete != NULL){
                delete todelete;
                todelete = NULL;
            }
            
        }
        return sentinel->next;
    }
};
