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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        int size = 1;
        ListNode* tmp = head;
        while(tmp->next){
            tmp = tmp->next;
            size++;
        }
        k = size - k % size;
        tmp->next = head;
        while(k--)tmp = tmp->next;
        head = tmp->next;
        tmp->next = NULL;
        return head;
    }
};