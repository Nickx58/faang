/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
*/

class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            if(head == nullptr) {
                return head;
            }
    
            ListNode* temp = head;
    
            while(temp != nullptr && temp->next != nullptr) {
                if(temp->val == temp->next->val) {
                    ListNode* curr = temp->next;
                    temp->next = temp->next->next;
                    delete curr;
                } else {
                    temp = temp->next;
                }
            }
            return head;
        }
    };