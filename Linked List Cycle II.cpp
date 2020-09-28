/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Approach 1: HashSet
// Time Complexity : O(N)
// Space comlexity : O(N)


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> st;
        while(head != NULL){
            if(st.find(head) != st.end()){
                return head;
            }
            st.insert(head);
            head = head -> next;
        }
        return NULL;
    }
};

// Approach 2: Two Pointer
// Time Complexity : O(N)
// Space comlexity : O(N)

class Solution {
public:
    ListNode* intersection(ListNode * head){
        if(head == NULL || head->next == NULL)
            return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow)
                return fast;
        }
        return NULL;
        
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = intersection(head);
        if(temp == NULL)
            return NULL;
        ListNode* ptr1 = head;
        ListNode* ptr2 = temp;
        while(ptr1 != ptr2){
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        return ptr1;
    }
};




