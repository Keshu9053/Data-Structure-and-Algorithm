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
    ListNode* reverse(ListNode*& head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* curr = NULL;
        ListNode* temp = head;

        while(temp != NULL){
            curr = temp->next;
            temp->next = prev;
            prev = temp;
            temp = curr;
        }
        return prev;
    }
    void Print(ListNode* head){
        while(head!=NULL){
            cout<<head->val<<"->";
            head=head->next;
        }
    }
    bool isPalindrome(ListNode* head) {
        ListNode* s = head;
        ListNode* f = head->next;
        while(f != NULL && f->next != NULL){
            s = s->next;
            f = f->next->next;
        }
       
        s->next = reverse(s->next);
        s = s->next;
        ListNode* dummy = head;
        while(s != NULL){
            if(dummy->val != s->val) return false;

            dummy = dummy->next;
            s = s->next;
        }
        return true;
    }
};