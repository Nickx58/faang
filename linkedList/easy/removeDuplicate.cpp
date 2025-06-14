class Solution {
    public:
      Node* removeDuplicates(Node* head) {
          // your code here
          if(head == nullptr || head->next == nullptr) {
              return head;
          }
          
          Node* temp = head;
          while(temp->next != nullptr) {
              if(temp->data == temp->next->data) {
                  Node* curr = temp->next;
                  temp->next = temp->next->next;
                  delete curr;
              } else {
                  temp = temp->next;
              }
          }
          return head;
      }
  };