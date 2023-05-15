
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp1;
        ListNode* temp2;
        ListNode* temp = head;
    
        int i = 0;
        int n = 0;
        while(temp != NULL) {
            temp = temp->next;
            n++;
        }
        if(n == 1) return head;
        // cout<<n-k+1;
        i = 1;
        temp = head;
        while(temp != NULL && i<=n) {
            if( i == k ) temp1 = temp;
            if( i == n-k+1) temp2 = temp;
            i++;
            temp = temp->next;
        }
        cout<<temp1->val<<endl;
        cout<<temp2->val;
        int a = temp1->val;
        temp1->val = temp2->val;
        temp2->val = a;
        return head;
    }
};