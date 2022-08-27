/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* checkA = headA;
       ListNode* checkB = headB;
       while(checkA != checkB){
           if(checkA == NULL) checkA = headB;
           else checkA = checkA->next;
           
           if(checkB == NULL) checkB = headA;
           else checkB = checkB->next;
           
       }
       
       return checkA;
    }
};