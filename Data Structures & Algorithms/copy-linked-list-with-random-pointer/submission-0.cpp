/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)   return head;

        unordered_map<Node* , Node*> m;

        Node* newHead = new Node(-1);
        Node* curr = newHead;    
        Node* temp = head;

        while(temp){
            Node* copyNode = new Node(temp -> val);
            curr -> next = copyNode;
            m[temp] = copyNode;

            curr = curr -> next;
            temp = temp -> next;
        }
        // if(temp){
        //     Node* copyNode = temp -> next;
        //     curr -> next = new Node(copyNode -> val);
        //     m[copyNode] = curr -> next;
        //     curr = curr -> next;
        //     curr -> next = nullptr;

        // }

        temp = head;
        curr = newHead -> next;
        while(temp){
            if(temp -> random){
                curr -> random = m[temp -> random];
            }
            else{
                curr -> random = nullptr;
            }
            temp = temp -> next;
            curr = curr -> next;
        }
        return newHead -> next;
    }
};
