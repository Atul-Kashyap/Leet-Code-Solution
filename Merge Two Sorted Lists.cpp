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



// Approach 1: Recursion
// Time Complexity : O(N+M)
// Space Complexity : O(N+M)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else{
            l2 -> next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};


// Approach 2: Iteration
// Time Complexity : O(N+M)
// Space Complexity : O(1)


    
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* prev = head;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                prev -> next = l1;
                prev = l1;
                l1 = l1 -> next;
            } else{
                prev -> next = l2;
                prev = l2;
                l2 = l2 -> next;
            }
        }
       prev -> next = l1 == NULL ? l2 : l1;
       return head->next;
    }
};



