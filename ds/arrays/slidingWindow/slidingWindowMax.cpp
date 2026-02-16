vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> result;

    for (int right = 0; right < nums.size(); right++)
    {

        // Remove elements smaller than current from back
        while (!dq.empty() && nums[dq.back()] < nums[right])
        {
            dq.pop_back();
        }

        dq.push_back(right);

        // Remove elements out of window from front
        if (dq.front() <= right - k)
        {
            dq.pop_front();
        }

        // Window formed
        if (right >= k - 1)
        {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}
