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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newhead = new ListNode(0);
        ListNode* merger = newhead;
        ListNode* temp = head->next;
        int sum=0;
        while(temp)
        {
            if(temp->val!=0)
            {
                sum+=temp->val;
            }
            else
            {
                ListNode* n = new ListNode(sum);
                newhead->next = n;
                newhead = newhead->next;
                sum=0;
            }
            temp=temp->next;
        }
        return merger->next;
    }
};