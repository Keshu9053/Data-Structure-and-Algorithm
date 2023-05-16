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
    ListNode* swapPairs(ListNode* head) {
        if( head == NULL ||head->next == NULL) return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        prev->next = head;
        ListNode* first = head;

        while(first != NULL && first->next != NULL) {
            prev -> next = first -> next;
            first ->next = first->next->next;
            prev->next->next = first;
            prev = first;
            first = first->next;
        }
       
        return dummy->next;

    }
};