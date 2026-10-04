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

    ListNode* getKthNode(ListNode* curr , int k){
        k -= 1;
        while(curr && k > 0){
            curr = curr -> next;
            k--;
        }
        if(k > 0)   return nullptr;

        return curr;
    }

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

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)   return head;

        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while(curr){
            ListNode* kth = getKthNode(curr , k);
            if(!kth){
                prev->next = curr;
                break;
            }
            next = kth -> next;
            kth -> next = nullptr;
            prev -> next = reverse(curr);

            prev = curr;
            curr = next;
        }
        return dummy -> next;
    }
};
