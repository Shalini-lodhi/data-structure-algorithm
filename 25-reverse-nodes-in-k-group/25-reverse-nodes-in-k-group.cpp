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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        //base case
        ListNode* kCount = head;
        for(int i=0; i< k; i++){
            if(kCount == NULL) return head;
            kCount = kCount -> next;
        }        
        
        //step1: reverse first k ListNode
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int count = 0;
        
        while(curr != NULL && count < k){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count ++;
        }
        
        //step2: recursion call
        head -> next = reverseKGroup(next, k);
        
        //step3: return head
        return prev;
    }
};