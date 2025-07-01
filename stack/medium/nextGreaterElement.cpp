class Solution
{
public:
    vector<int> nextLargerElement(vector<int> &arr)
    {
        // Initialize the stack to hold elements in decreasing order
        stack<int> st;
        // Initialize the result vector with -1 for all elements
        vector<int> ans(arr.size(), -1);

        // Traverse the array from the second last element to the first
        for (int i = arr.size() - 2; i >= 0; i--)
        {
            // Pop elements from the stack while the current element is greater than or equal to the stack's top
            while (!st.empty() && arr[i] >= st.top())
            {
                st.pop();
            }

            // If the stack is not empty, the top of the stack is the next greater element
            if (!st.empty())
            {
                ans[i] = st.top();
            }

            // Push the current element onto the stack
            st.push(arr[i]);
        }

        return ans;
    }
};
