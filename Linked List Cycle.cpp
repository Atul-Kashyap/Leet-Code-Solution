/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Approach 1: Hash Set
// Time complexity : O(N);
// Space Complexity : O(N)


// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         set<ListNode*> st;
//         while(head != NULL ){
//            if(st.find(head) != st.end())
//                return true;
//             st.insert(head);
//             head = head -> next;
//         }
//         return false;
//     }
// };



// Approach 2: Two Pointer
// Time complexity : O(N+k); k is cyclic length
// Space Complexity : O(1)


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL)
            return false;
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(slow != fast){
            if(fast == NULL || fast -> next == NULL)
                return false;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
      return true;  
    }
};










