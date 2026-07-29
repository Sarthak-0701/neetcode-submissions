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
    
    void merge(ListNode* first , ListNode* second){
        ListNode* curr = first;
        ListNode* temp1 = first -> next;
        ListNode* temp2 = second;
        while(temp1 && temp2){
            if(temp1 -> val <= temp2 -> val){
                curr -> next = temp1;
                curr = temp1;
                temp1 = temp1 -> next;
            }
            else{
                curr -> next = temp2;
                curr = temp2;
                temp2 = temp2 -> next;
            }
        }
        if(temp1){
            curr -> next = temp1;
        }
        if(temp2){
            curr -> next = temp2;
        }

    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)   return list2;
        if(list2 == NULL)   return list1;

        if(list1 -> val <= list2 -> val){
            merge(list1 , list2);
            return list1;
        }
        else{
            merge(list2 , list1);
            return list2;
        }

    }
};
