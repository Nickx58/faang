class Solution {
    public:
      int getMiddle(Node* head) {
          // your code here
          if(head == nullptr || head->next == nullptr) {
              return -1;
          }
          Node* slow = head;
          Node* fast = head;
          while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
          }
          return slow->data;
      }
  };