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
    int pairSum(ListNode* head) {
		ListNode* head1;
        ListNode* temp = head;
        ListNode* temp1 = new ListNode(-1);
        head1 = temp1;
        
        while(temp!=NULL){
            temp1->next = new ListNode(temp->val);
            temp = temp->next;
            temp1 = temp1->next;
        }
        temp1->next = NULL;
        
        
        head1 = head1->next;
        
        ListNode* prev = NULL;
        ListNode* curr = head1;
        ListNode* next = curr;
        
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        ListNode* head3 = prev;
        ListNode* head4 = head;
        int ans = INT_MIN;
        while(head3 != NULL && head4 != NULL){
            // cout<<head3->val<<" "<<head4->val<<" \n";
            ans = max(ans, head3->val+head4->val);
            head3 = head3->next;
            head4 = head4->next;
            
        }
        
        return ans;
        
    }
};