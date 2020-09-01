Approach: iterative using simple maths 
Time Complexity: O(max(m,n)) { m and n are the size of the linked list. }
Auxiliary Space : O(max(m,n) { m and n are the size of the linked list and O(max(m,n)) + 1 , +1 for carry }

/**
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
        ListNode* head = new ListNode(0);
        ListNode* curr_node = head;
        int carry = 0, sum;
        while(l1 != NULL || l2 != NULL){
            int x = (l1 != NULL) ? l1->val : 0;
            int y = (l2 != NULL) ? l2->val : 0;
            sum = x + y + carry;
            carry = sum / 10;
            curr_node -> next = new ListNode(sum%10);
            if(l1 != NULL) l1 = l1 -> next;
            if(l2 != NULL) l2 = l2 -> next;
            curr_node = curr_node -> next;
        }
       
        if(carry > 0)
            curr_node -> next = new ListNode(carry);
        
       return head->next; 
    }
};


