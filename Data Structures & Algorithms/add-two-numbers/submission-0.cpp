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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp3 = dummy;
        int carry = 0;
        int sum = 0;
        while(temp1 || temp2){
            int val1 = 0;
            int val2 = 0;
            if(temp1){
                val1 = temp1 -> val;
                temp1 = temp1 -> next;
            }
            if(temp2){
                val2 = temp2 -> val;
                temp2 = temp2 -> next;
            }
            sum = carry + val2 + val1;
            carry = sum/10;
            sum = sum%10;
            temp3 -> next = new ListNode(sum);
            temp3 = temp3 -> next;
        }
        if(carry == 1){
            temp3 -> next = new ListNode(1);
            temp3 = temp3 -> next;
        }
        return dummy -> next;
    }
};
