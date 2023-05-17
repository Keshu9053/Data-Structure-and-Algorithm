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
    ListNode* reverse(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp = curr;
        while(curr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
public:
    int pairSum(ListNode* head) {
        int ans = 0;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverse(slow->next);
        fast = slow->next;
        slow = head;
        
        while(fast != NULL) {
            ans = max(ans , slow->val + fast->val);
            slow = slow->next;
            fast = fast->next;
        }
        return ans;

    }
};