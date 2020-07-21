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

Brute force Approach 1:
Time Complexity : O(N) { N is the size of linked list }
Auxiliaxy space : O(N)
// Traverse Linked List Twice

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int> v;
        for(ListNode *node = head; node != NULL; node = node -> next){
            v.push_back(node -> val);
        }
       for(ListNode *curr = head; curr != NULL; curr = curr -> next){
           curr -> val = v.back();
           v.pop_back();
       }
        return head;
    }
};

Efficient Solution 2 :
Time Complexity : O(N) { N is the size of linked list }
Auxiliaxy space : O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head;
        ListNode *prev = NULL;
        while(curr != NULL){
            ListNode *next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

