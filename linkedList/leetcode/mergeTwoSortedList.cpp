class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if(list1 == nullptr && list2 == nullptr) {
                return list1;
            }
    
            vector<int> list = {};
    
            ListNode* temp1 = list1;
    
            while(temp1 != nullptr) {
                list.push_back(temp1->val);
                temp1 = temp1->next;
            }
    
            ListNode* temp2 = list2;
    
            while(temp2 != nullptr) {
                list.push_back(temp2->val);
                temp2 = temp2->next;
            }
    
            sort(list.begin(), list.end());
    
            ListNode* newNode = new ListNode(list[0]);
            ListNode* curr = newNode;
            for(int i = 1; i<list.size();i++) {
                curr->next = new ListNode(list[i]);
                curr = curr->next;
            }
            return newNode;
        }
    };

/*

 This is not the fully optimzed version
 I will add more solution going forward

*/