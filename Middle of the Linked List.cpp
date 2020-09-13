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

Approach 1: array
Time Complexity: O(N)  where N is the number of nodes in the given list.
Space Complexity: O(N)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> arr = {head};
        while(head->next != NULL){
            arr.push_back(head->next);
            head = head -> next;
        }
        return arr[arr.size() / 2];
    }
};


Approach 1: Slow and Fast Pointer
Time Complexity: O(N)  where N is the number of nodes in the given list.
Space Complexity: O(1)


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow -> next;
            fast = fast->next->next;
        }
      return slow;  
    }
};
