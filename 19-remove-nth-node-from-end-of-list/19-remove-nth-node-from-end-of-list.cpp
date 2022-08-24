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
    //reversing linked list
    ListNode* reverseLinkedList(ListNode* &head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
             prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         if(head==NULL) 
            return NULL;
        if(head->next==NULL && n==1)
            return NULL; 
        auto curr = head;
        curr = reverseLinkedList(curr);
        
       ListNode* temp=curr;
        if(n==1)
        {
            curr=temp->next;   
        }
        else
        {
            for(int i=0;i<n-2;i++)
            {
                temp=temp->next;
            }
            
            temp->next=temp->next->next;
    }
        return reverseLinkedList(curr);
    }
};