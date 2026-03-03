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
class Solution
{
public:
    int pairSum(ListNode *head)
    {
        vector<int> arr;
        ListNode *temp = head;

        while (temp)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int i = 0;
        int j = arr.size() - 1;

        int maxi = INT_MIN;

        while (i < j)
        {
            int sum = arr[i] + arr[j];
            maxi = max(maxi, sum);
            i++;
            j--;
        }
        return maxi;
    }
};

/*
    Using fast and slow pointer
    1. Reach the middle of the linked list
    2. Reverse the linked list after the middle point
    3. Use two pointer for sum
*/

class Solution
{
public:
    int pairSum(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = nullptr;

        while (slow)
        {
            ListNode *nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        ListNode *first = head;
        ListNode *second = prev;
        int maxi = INT_MIN;
        while (first && second)
        {
            int sum = first->val + second->val;
            maxi = max(maxi, sum);
            first = first->next;
            second = second->next;
        }
        return maxi;
    }
};