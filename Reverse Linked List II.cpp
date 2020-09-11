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
 
 
 Approach 2: Iterative Linked List Reversal
 Time Complexity: O(N)
 Space Complexity: O(1)
 
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
         if(head == NULL)
             return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(m > 1){
            prev = curr;
            curr = curr -> next;
            m--; 
            n--;
        }
        ListNode *con = prev;
        ListNode * tail = curr;
        
        ListNode *third = NULL;
        while(n > 0){
            third = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = third;
            n--;
            
        }
        if(con != NULL)
            con -> next = prev;
        else
            head = prev;
        
        tail->next =curr ;
        return head;
            
    }
};
