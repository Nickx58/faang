class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            if(head == NULL) {
                return true;
            }
            vector<int> arr = {};
            ListNode* temp = head;
    
            while(temp != nullptr) {
                arr.push_back(temp->val);
                temp = temp->next;
            }
    
            int start = 0;
            int end = arr.size()-1;
            while(start < end) {
                if(arr[start] != arr[end]) {
                    return false;
                }
                start++;
                end--;
            }
            return true;
        }
    };