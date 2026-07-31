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

    ListNode* reverse(ListNode* head){
        if(!head)   return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while(curr){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;

    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)   return head;
        if(!head -> next)   return nullptr;
        head = reverse(head);
        ListNode* curr = head;
        ListNode* prev = nullptr;
        int count = 1;
        while(count < n){
            prev = curr;
            curr = curr -> next;
            count++;
        }
        if(!prev){
            prev = curr -> next;
            head = prev;
        }
        else{
            prev -> next = curr -> next;
        }
        curr -> next = nullptr;
        delete(curr);
        head = reverse(head);
        return head;
    }
};
