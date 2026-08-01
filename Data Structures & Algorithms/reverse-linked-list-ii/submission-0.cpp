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

    ListNode* reverse(ListNode* head , ListNode* &tail){
        if(!head)   return head;
        tail = head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while(curr){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;

    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* start = head;
        ListNode* prev = nullptr;
        ListNode* tail = head;
        while(left > 1 || right > 1){
            if(left > 1){
                prev = start;
                start = start -> next;
                left--;
            }
            tail = tail -> next;
            right--;
        }
        ListNode* rest = tail -> next;
        tail -> next = nullptr;
        if(prev){
            prev -> next = reverse(start,tail);
        }   
        else{
            head = reverse(head , tail);
        }
        tail -> next = rest;
        return head;
    }
};